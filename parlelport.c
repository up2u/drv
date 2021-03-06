#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/proc_fs.h>
#include <linux/fcntl.h>
#include <linux/ioport.h>
#include <asm/system.h>
#include <asm/uaccess.h>
#include <asm/io.h>

MODULE_LICENSE("Dual BSD/GPL");

int parlelport_open(struct inode *inode, struct file *filp);
int parlelport_release(struct inode *inode, struct file *filp);
ssize_t parlelport_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
ssize_t parlelport_write(struct file *filp, char *buf, size_t count, loff_t *f_pos);
void parlelport_exit(void);
int parlelport_init(void);

struct file_operations parlelport_fops = {
	read: parlelport_read,
	write: parlelport_write,
	open: parlelport_open,
	release: parlelport_release	
};

int parlelport_major = 61;
int port;

module_init(parlelport_init);
module_exit(parlelport_exit);

int parlelport_init(void) {
	int result;
	result = register_chrdev(parlelport_major, "parlelport", &parlelport_fops);
	if(result < 0) {
		printk("<1>parlelport:cannot obtain major number %d\n",parlelport_major);
		return result;	
	}

	printk("<1> Inserting parlelport module\n");
	return 0;
}

void parlelport_exit(void) {
	unregister_chrdev(parlelport_major, "parlelport");	
	printk("<1> Remove parlelport module\n");
}

int parlelport_open(struct inode *inode, struct file *filp) {
	return 0;	
}

int parlelport_release(struct inode *inode, struct file *filp) {
	return 0;	
}

ssize_t parlelport_read(struct file *filp, char *buf, size_t count, loff_t *f_pos) {
	char parlelport_buffer = 'r';
	copy_to_user(buf, &parlelport_buffer, 1);
	printk("<1> my parlelport read is %c\n", *buf);
	
	if(*f_pos == 0) {
		*f_pos+=1;
		return 1;	
	}else{
		return 0;	
	}
}

ssize_t parlelport_write(struct file *filp, char *buf, size_t count, loff_t *f_pos) {
	char *tmp;
	char parlelport_buffer;
	tmp = buf+count-1;
	printk("<1> my parlelport write is %c\n", *buf);
	copy_from_user(&parlelport_buffer, tmp, 1);
	
	return 1;	
}

