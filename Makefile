obj-m := hello_args.o

KERNEL_PATH := /usr/src/linux-headers-2.6.35-23-generic
#KERNEL_PATH := /usr/src/kernels/2.6.23.1-42.fc8-i686
CURRENT_PATH := $(shell pwd)

all:
	make -C $(KERNEL_PATH)  M=$(CURRENT_PATH) modules
clean:
	rm -f *.o *.mod *.ko
