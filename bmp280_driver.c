#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/i2c.h>
#include <stddef.h>

#define SLAVE_DEVICE_NAME    ( "BMP_280" )
#define SLAVE_ADDR           0x76
#define I2C_BUS_NUM          1

// Credits
MODULE_AUTHOR("Pawel Wisniewski");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("I2C driver for BMP280 sensor.");
MODULE_VERSION("0.1");


// I2C handlers
static struct i2c_adapter *bpm280_i2c_adapter = NULL;
static struct i2c_client *bmp280_i2c_client = NULL;

// Board info
static struct i2c_board_info raspi_i2c_board_info = {
	I2C_BOARD_INFO(SLAVE_DEVICE_NAME, SLAVE_ADDR)
};

static int __init bmp280_driver_init(void) {
	printk(KERN_INFO "BMP280 Driver Initialization Done");
	return 0;
}

static void __exit bmp280_driver_exit(void) {
	printk(KERN_INFO "BMP280 Driver exit.");
}

module_init(bmp280_driver_init);
module_exit(bmp280_driver_exit);

