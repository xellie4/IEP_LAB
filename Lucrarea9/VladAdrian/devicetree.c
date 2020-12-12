//here is the demo from the provided link, I ran in some issues with init.h, platform_device.h, of.h but in the end I managed to solve them
//a very nice presentation though

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/of.h>

static struct of_device_id testdev_ids[] =
{
    {.compatible = "test,mydevice"},
    {.compatible = "test,mytestdevice"},
    {/*sentinel to terminate list*/},
};
MODULE_DEVICE_TABLE(of, testdev_ids);

static int testdev_probe(struct platform_device *drv){
    const char *mystring = NULL;
    int u32val = 0;
    struct device_node *np = drv->dev.of_node;
    int arr[4] = {0};

    printk("Hello from platform device %s\n", drv->name);

    of_property_read_string(np, "string-property", &mystring);
    printk("string from dtb: %s\n", mystring);

    of_property_read_u32(np, "number_property", &u32val);
    printk("number from dtb: %d\n", u32val);

    for_each_child_of_node(np, child){
        other = of_parse_phandle(child, "child-property", 0);

        if(!other){
            printk("FAIL\n");
            return 0 ;
        }
        of_property_read_u32(other, "cell property", arr, 4);
        printk("array from other node in dtb: [%d, %d, %d, %d]\n", arr[0], arr[1], arr[2], arr[3]);
    }

    return 0;
}

static int testdev_remove(struct platform_device *drv)
{
    printk("my device removed\n");
    return 0;
}

static struct platform_driver pdrv = {
    .probe = testdev_probe,
    .remove = testdev_remove,
    .driver = {
        .name = "testdevdrv",
        .of_match_table = of_match_ptr(testdev_ids),
        .owner = THIS_MODULE,
    },
};

module_platform_driver(pdrv);

MODULE_AUTHOR("Vlad Adrian");
MODULE_DESCRIPTION("Demo from the provided link");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");