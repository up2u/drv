#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

static char *name="maolijie";
static int num=45;
module_param(name, charp, S_IRUGO);
module_param(num, int, S_IRUGO);

static int hello_init(void) {
	printk("<1> Hello world!,name=%s,num=%d\n",name, num);
	return 0;
}

static void hello_exit(void) {
	printk("<1> Bye, cruel world!\n");
}

module_init(hello_init);
module_exit(hello_exit);

