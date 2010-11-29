obj-m := nothing.o

#KERNEL_PATH := /lib/modules/2.6.35-23-generic/build
KERNEL_PATH := /usr/src/linux-headers-2.6.35-23-generic
CURRENT_PATH := $(shell pwd)

all:
	make -C $(KERNEL_PATH)  M=$(CURRENT_PATH) modules
clean:
	rm -f *.o *.mod *.ko
