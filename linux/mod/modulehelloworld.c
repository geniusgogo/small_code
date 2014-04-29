#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("geniusgogo");

static int __init hello_init(void)
{
    printk(KERN_ALERT "(init) hello, world!\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_ALERT "(exit) hello, world!\n");
}

module_init(hello_init);
module_exit(hello_exit);

