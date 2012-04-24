
#global defines
RM := rm -f
CFLAGS := -c -g3
LDFLAGS := -lc
GCC := gcc
#LD := ld
LD := gcc

dirs := cmd


all: test.elf

srcs := $(wildcard ${dirs}/*.c *.c)
OBJS := $(subst %.c,%.o,${srcs})

test.elf: ${OBJS}
	$(LD) ${LDFLAGS} -o $@ $^

%.o:%.c
	${GCC} ${CFLAGS} -o $@ $<

controller.c : cmd/command.h
command.c : command.h

.PHONY : clean
clean:
	find . -name "*.[oa]" | xargs ${RM} ;\
	find . -name "*.elf"  -exec ${RM} {} \; ;\
	find . -name "*.out"  -exec ${RM} {} \; ;\
	echo "now I'm in path:"`pwd`
