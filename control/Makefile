
#global defines
RM := rm -f
INCPATH := -I./macro/ -I./cmd/ -I./node/ -I./config/
CFLAGS := -c -g3 ${INCPATH}
LDFLAGS := -lc

GCC := gcc
#LD := ld
LD := gcc

dirs := cmd
srcs := $(wildcard ${dirs}/*.c *.c)
OBJS := $(srcs:.c=.o)

all: test.elf

test.elf: ${OBJS}
	$(LD) ${LDFLAGS} -o $@ $^

%.o:%.c
	${GCC} ${CFLAGS} -o $@ $<

%.d:%.c
	set -e; rm -f $@; \
	${GCC} -MM ${CFLAGS} $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$



.PHONY : clean
clean:
	find . -name "*.[oa]" | xargs ${RM} ;\
	find . -name "*.elf"  -exec ${RM} {} \; ;\
	find . -name "*.out"  -exec ${RM} {} \; ;\
#	echo "path:"`pwd`
