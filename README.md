# pcf8591t_driver_kernel
Kernel module which handles PCF8591T AC/DC conventer. For now implementation contains only AIN1 reading (rest of pins will be delivered in a future).
Module registers a character device. You can make node under /dev directory to create a special file and read values from it.

This is 8 bits conventer so returning type is unsigned char (C).

Default major number for a chdev is 240.

## Compilation
```bash
make
```

## Inserting a module into a kernel space
```bash
sudo insmod pcf8591t_driver.ko
```

## Creating a character device
```bash
sudo mknod -m 755 /dev/pcf_device c 240 0
```

## Reading example in python
Please notice that PCF8591T is a 8 bits conventer so we need to read exacly 1 byte.
```python
with open("/dev/pcf_device") as f:
  print(f.read(1))
```
