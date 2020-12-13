#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_DESCRIPTION("Kernel Module");
MODULE_AUTHOR("Vlad");
MODULE_LICENSE("GPL");

int sum(int a, int b){
    return a+b;
}

static int dummy_init(void)
{
        pr_debug( "Here is the sum of 2 numbers:\n");
        pr_debug("%d", sum(1, 2));
        return 0;
}

static void dummy_exit(void)
{
        pr_debug("Sum is done! Exit!");
}

module_init(dummy_init);
module_exit(dummy_exit);