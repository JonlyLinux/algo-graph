target=graph

compiler=gcc

language_std = -std=gnu99
#language_std = -std=c99

compile_opts=-g -c -fstrict-aliasing

optimize_opts = -O3

#warning_opts = -Wunused-function 
#warning_opts += -Wunused-label 
#warning_opts += -Wunused-parameter 
#warning_opts += -Wunused-variable
#warning_opts += -Wunused-value
warning_opts += -Wformat
warning_opts += -Wimplicit-int
warning_opts += -Wimplicit-function-declaration
warning_opts += -Wchar-subscripts
warning_opts += -Wmissing-braces
warning_opts += -Wparentheses
warning_opts += -Wreturn-type
warning_opts += -Wsequence-point
warning_opts += -Wswitch
warning_opts += -Wstrict-aliasing=3
warning_opts += -Wunknown-pragmas
warning_opts += -Wuninitialized

warning_opts += -Wcast-align
warning_opts += -Wsign-compare
warning_opts += -Wmissing-prototypes
warning_opts += -Wpadded
#warning_opts += -Wpacked
#warning_opts += -Wunreachable-code
warning_opts += -Winline
#warning_opts += -Wdisable-optimization
warning_opts += -Werror

ld_opts=-lpthread

objects += main.o
objects += graph_present.o
objects += graph_search.o

$(target) : $(objects)
	$(compiler) $(ld_opts) $(objects) -o $(target)

main.o : main.c
	$(compiler) $(language_std) $(compile_opts) $(optimize_opts) $(warning_opts) $<

graph_present.o : graph_present.c
	$(compiler) $(language_std) $(compile_opts) $(optimize_opts) $(warning_opts) $<

graph_search.o : graph_search.c
	$(compiler) $(language_std) $(compile_opts) $(optimize_opts) $(warning_opts) $<

clean:
	rm -f $(objects) $(target)
