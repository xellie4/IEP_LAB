#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

string add_string(string s1, string s1){
    return s1+s2;
}

static int ex_init(void)
{
    printk(KERN_INFO "Adaugare stringuri:\n");
    add_string("buna","seara");
}

static void ex_exit(void)
{
    printk(KERN_INFO "S-a finalizat cu succes -> exit\n");
}

module_init(ex_init);
module_exit(ex_exit);