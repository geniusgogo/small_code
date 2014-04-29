#ifndef _GLOBALCHARDEV_H_
#define _GLOBALCHARDEV_H_

static ssize_t globalchar_read(struct file *, char *, size_t, loff_t *);
static ssize_t globalchar_write(struct file *, const char *, size_t, loff_t *);

#endif

