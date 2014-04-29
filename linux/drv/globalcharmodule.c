#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

#include "globalchardev.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("geniusgogo");

#define DEV_NAME "GlobalChar"

static struct file_operations globalchar_fops = 
{
    .read = globalchar_read,
    .write = globalchar_write
};

static int char_major = 0;

static int __init globalchar_init(void)
{
    int ret;

    ret = register_chrdev(char_major, DEV_NAME, &globalchar_fops);

    if (ret < 0)
    {
        printk(KERN_ALERT DEV_NAME "register fail!\n");
    }
    else
    {
        char_major = ret;
        ret = 0;
        printk(KERN_ALERT DEV_NAME "register success!\n");
        printk(KERN_ALERT "major = %d\n", char_major);
    }

    return ret;
}

static void __exit globalchar_exit(void)
{
    unregister_chrdev(char_major, DEV_NAME);
    printk(KERN_ALERT DEV_NAME "unregisted\n");
}

module_init(globalchar_init);
module_exit(globalchar_exit);

#include "globalchardev.c"
