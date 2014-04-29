#include <linux/fs.h>
#include <asm/uaccess.h>

#include "globalchardev.h"

static int globalchar_data = 0;

ssize_t globalchar_read(struct file *filp, char *buf, size_t len, loff_t *off)
{
    if (copy_to_user(buf, &globalchar_data, sizeof(int)))
    {
        return -EFAULT;
    }

    return sizeof(int);
}

ssize_t globalchar_write(struct file *filp, const char *buf, size_t len, loff_t *off)
{
    if (copy_from_user(&globalchar_data, buf, sizeof(int)))
    {
        return -EFAULT;
    }

    return sizeof(int);
}

