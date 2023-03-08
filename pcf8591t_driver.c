#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/i2c.h>
#include <stddef.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#define MODULE_NAME          "PCF8591T_DRIVER"
#define SLAVE_DEVICE_NAME    ( "PCF8591T" )
#define DEVICE_ADDR          0x48
#define AIN1                 0x40
#define I2C_BUS_NUM          1

// Credits
MODULE_AUTHOR("Pawel Wisniewski");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("I2C driver for BMP280 sensor.");
MODULE_VERSION("0.1");

//file operation functions
static int driver_open(struct inode *pinode, struct file *pfile) {
	printk(KERN_ALERT "Inside the %s fun\n", __FUNCTION__);
	return 0;
}

char msg[] = "Hello\0";
int len = 6;
static ssize_t driver_read(struct file *pifile, char __user *buffer, size_t length, loff_t *offset) {
	int ret;
    ret = copy_to_user(buffer, msg, len);
	printk(KERN_ALERT "[%s] Inside the read: [%d]\n", MODULE_NAME, ret);
	return length;
}

static int driver_close(struct inode *pinodem, struct file *pifile) {
	printk(KERN_ALERT "Inside the %s fun \n", __FUNCTION__);
	return 0;
}

//driver fo
static const struct file_operations driver_file_operations = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.read = driver_read,
	.release = driver_close,
};

//module init fun
static int pcf_driver_init(void) {
	printk(KERN_ALERT "[%s] Init: Driver init\n", MODULE_NAME);
	//chrdev registration
	register_chrdev(240, "simple chrdev", &driver_file_operations);
	return 0;
}

//module exit fun
static void pcf_driver_exit(void) {
	printk(KERN_ALERT "[%s] Exit\n", MODULE_NAME);
	//chrdev unregister 
	unregister_chrdev(240, "siple chrdev");
}

module_init(pcf_driver_init);
module_exit(pcf_driver_exit);
