#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>

#include <hello1.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("AK-2 lab_5 advanced task: hello2");
MODULE_AUTHOR("Zakharchuk IV-82");

static uint n = 1;
module_param(n, uint, 0);
MODULE_PARM_DESC(n, "How many hello to print");

static int hello_init(void)
{
        return print_hello(n);
}

static void hello_exit(void)
{
        printk(KERN_ALERT "hello2 exit\n");
}

module_init(hello_init);
module_exit(hello_exit);
