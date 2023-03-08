obj-m = pcf8591t_driver.o

KERN_VER = $(shell uname -r)
PWD = $(shell pwd)

all:
	make -C /lib/modules/$(KERN_VER)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KERN_VER)/build M=$(PWD) clean
