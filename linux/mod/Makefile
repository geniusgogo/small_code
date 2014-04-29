ifneq ($(KERNELRELEASE),)
	obj-m += helloworldmod.o
helloworldmod-objs := modulehelloworld.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
		$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
		$(MAKE) -C $(KERNELDIR) M=$(PWD) modules clean
endif

