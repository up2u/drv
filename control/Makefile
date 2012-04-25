#global defines
RM := rm -f
INCPATH := -I./defines/ -I./cmd/ -I./node/ -I./types/
CFLAGS := -c -g3 ${INCPATH}
LDFLAGS := -lc -lpthread

CC := gcc
#LD := ld
LD := gcc

include ${srcs:%.c=%.d}

DIRS := sim cmd node .
SRCS := $(foreach subdir,${DIRS},$(wildcard ${subdir}/*.c))
OBJS := $(SRCS:.c=.o)

all: test.elf

test.elf: ${OBJS}
	$(LD) ${LDFLAGS} -o $@ $^

%.o:%.c
	${CC} ${CFLAGS} -o $@ $<

%.d:%.c
	set -e; rm -f $@; \
	${CC} -MM ${CFLAGS} $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$



.PHONY : clean
clean:
	find . -name "*.[oa]" | xargs ${RM} ;\
	find . -name "*.elf"  -exec ${RM} {} \; ;\
	find . -name "*.out"  -exec ${RM} {} \; ;\
#	echo "path:"`pwd`
