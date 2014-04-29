ifneq ($(KERNELRELEASE),)
	obj-m += globalcharmod.o
globalcharmod-objs := globalchardev.o globalcharmodule.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
		$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
endif

