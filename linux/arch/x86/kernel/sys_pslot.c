#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>

asmlinkage long	sys_pslot(int a, int b)
{
	#ifdef CONFIG_PROC_PSLOT

	printk(KERN_INFO "pslot syscall is called\n");
	#else
		printk(KERN_WARN "pslot called failed CONFIG_PROC_PSLOT=n");
		return -1;
	#endif
	return 0;
}
