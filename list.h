#ifndef __LIST_H__
#define __LIST_H__

/*
 *  * These are non-NULL pointers that will result in page faults
 *   * under normal circumstances, used to verify that nobody uses
 *    * non-initialized list entries.
 *     */
# define POISON_POINTER_DELTA 0
#define LIST_POISON1  ((void *) 0x00100100 + POISON_POINTER_DELTA)
#define LIST_POISON2  ((void *) 0x00200200 + POISON_POINTER_DELTA)

struct list_head {
	struct list_head *prev;
	struct list_head *next;
};

typedef struct list_head list_head_t;

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

static inline void __list_add(struct list_head *new,
		struct list_head *prev,
		struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
}

static inline void __list_del(struct list_head * prev, struct list_head * next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	entry->next = LIST_POISON1;
	entry->prev = LIST_POISON2;
}

/**
 *  * list_move - delete from one list and add as another's head
 *   * @list: the entry to move
 *    * @head: the head that will precede our entry
 *     */
static inline void list_move(struct list_head *list, struct list_head *head)
{
	__list_del(list->prev, list->next);
	list_add(list, head);
}

/**
 *  * list_move_tail - delete from one list and add as another's tail
 *   * @list: the entry to move
 *    * @head: the head that will follow our entry
 *     */
static inline void list_move_tail(struct list_head *list,
		struct list_head *head)
{
	__list_del(list->prev, list->next);
	list_add_tail(list, head);
}


/**
 *  * list_is_last - tests whether @list is the last entry in list @head
 *   * @list: the entry to test
 *    * @head: the head of the list
 *     */
static inline int list_is_last(const struct list_head *list,
		const struct list_head *head)
{
	return list->next == head;
}

/**
 *  * list_empty - tests whether a list is empty
 *   * @head: the list to test.
 *    */
static inline int list_empty(const struct list_head *head)
{
	return head->next == head;
}

//计算member在type中的位置
#define offsetof(type, member)  (size_t)(&((type*)0)->member)
//根据member的地址获取type的起始地址
#define container_of(ptr, type, member) ({          \
        const typeof(((type *)0)->member)*__mptr = (ptr);    \
            (type *)((char *)__mptr - offsetof(type, member)); })


/**
 *  * list_entry - get the struct for this entry
 *   * @ptr:    the &struct list_head pointer.
 *    * @type:    the type of the struct this is embedded in.
 *     * @member:    the name of the list_struct within the struct.
 *      */
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

/**
 *  * list_first_entry - get the first element from a list
 *   * @ptr:    the list head to take the element from.
 *    * @type:    the type of the struct this is embedded in.
 *     * @member:    the name of the list_struct within the struct.
 *      *
 *       * Note, that list is expected to be not empty.
 *        */
#define list_first_entry(ptr, type, member) \
	list_entry((ptr)->next, type, member)

/**
 *  * list_for_each    -    iterate over a list
 *   * @pos:    the &struct list_head to use as a loop cursor.
 *    * @head:    the head for your list.
 *     */
#define list_for_each(pos, head) \
	for (pos = (head)->next; prefetch(pos->next), pos != (head); \
			pos = pos->next)



#endif
