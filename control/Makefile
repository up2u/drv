
#global defines
RM := rm -f
CFLAGS := -c -g3
LDFLAGS := -lc
GCC := gcc
#LD := ld
LD := gcc



all: test.elf

OBJS := controller.o command.o

test.elf: ${OBJS}
	$(LD) ${LDFLAGS} -o $@ $^

%.o:%.c
	${GCC} ${CFLAGS} -o $@ $<

controller.c : command.h
command.c : command.h

.PHONY : clean
clean:
	find . -name "*.[oa]" | xargs ${RM} ;\
	find . -name "*.elf"  -exec ${RM} {} \; ;\
	find . -name "*.out"  -exec ${RM} {} \; ;\
	echo "now I'm in path:"`pwd`
