obj-m := devicetree.o

KDIR := /usr/src/linux-headers-$(uname -r)

PWD := $(pwd) 
default:

	make -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *o
