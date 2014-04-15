#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/list.h>

asmlinkage long	sys_pslot(int control, void __user *buf)
{
	#ifdef CONFIG_PROC_PSLOT
	/* When monitoring must be started, we must reset the linked list
	 * to avoid bad result
	 */
	if (control == 0)
	{
		pslot_state = PSLOT_STATE_START;
		struct list_head *l, *q;
		list_for_each_safe(l, q, &init_pslot_list)
		{
			struct pslot_linked_entity *entry = list_entry(l, struct pslot_linked_entity, list);
			list_del(l);
			kfree(entry);
		}
		LIST_HEAD(init_pslot_list);
		goto pslot_normal_exit;
	}
	else if (control == -1)
		pslot_state = PSLOT_STATE_STOP;
	else if (control > 0)
	{
		copy_to_user(buf, &control, sizeof(int));
		//(int)(*buf) = control;
	}
	return 0;
	#endif

	printk(KERN_INFO "pslot called failed CONFIG_PROC_PSLOT=n");
	return -1;

	pslot_normal_exit:
		return 0;
}
