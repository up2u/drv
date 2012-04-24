
#global defines
RM := rm -f
INCPATH := -I./macro/ -I./cmd/
CFLAGS := -c -g3 ${INCPATH}
LDFLAGS := -lc

GCC := gcc
#LD := ld
LD := gcc

dirs := cmd
srcs := $(wildcard ${dirs}/*.c *.c)
OBJS := $(patsubst %.c,%.o,${srcs})

all: test.elf

test.elf: ${OBJS}
	$(LD) ${LDFLAGS} -o $@ $^

%.o:%.c
	${GCC} ${CFLAGS} -o $@ $<

controller.c : cmd/command.h
command.c : command.h defines.h

.PHONY : clean
clean:
	find . -name "*.[oa]" | xargs ${RM} ;\
	find . -name "*.elf"  -exec ${RM} {} \; ;\
	find . -name "*.out"  -exec ${RM} {} \; ;\
	echo "path:"`pwd`
