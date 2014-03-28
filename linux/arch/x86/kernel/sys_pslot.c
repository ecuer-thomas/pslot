#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

asmlinkage long	sys_pslot(int a, int b)
{
	printk(KERN_INFO "pslot syscall is called\n");
	return 0;
}
