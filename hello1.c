#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>

#include <hello1.h>

MODULE_LICENSE("Dual BSD/GPL\n");
MODULE_DESCRIPTION("AK-2 lab_5 advanced task: hello1\n");
MODULE_AUTHOR("Zakharchuk IV-82\n");

EXPORT_SYMBOL(print_hello);

static int print_hello(uint n)
{
        int i;
        if (n < 0) {
                pr_err("ERROR! n < 0\n");
        }
        else if (n == 0) {
                pr_warn("WARNING! n = 0\n");
        }
        else if (n >= 5 && n <= 10) {
                pr_warn("WARNING! 5 <= n <= 10\n");
        }
        else if (n > 10) {
                pr_err("ERROR! n > 10\n");
                return -EINVAL;
        }
        for (i = 0; i < n; i++) {
                pr_info("Hello, world!\n");
        }
        return 0;
}

static int __init hello1_init(void)
{
        pr_info("hello1 init\n");
        return 0;
}

static void __exit hello1_exit(void)
{
        pr_info("hello1 exit\n");
}

module_init(hello1_init);
module_exit(hello1_exit);
