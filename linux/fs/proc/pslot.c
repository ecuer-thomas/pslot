#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#include "internal.h"

#include <linux/sched.h>
#include <linux/uaccess.h>

struct proc_dir_entry	*proc_file_entry;

static ssize_t pslot_read(struct file* f, char __user* u , size_t n, loff_t *o)
{
	printk(KERN_INFO "Read some stuff here but no.\n");
	static struct list_head *l = NULL;
	static struct list_head *q = NULL;
	char *buffered = vmalloc(sizeof(char) + n);
	char string[100];

	int len = 0;
	list_for_each_safe(l, q, &init_pslot_list)
	{
		struct pslot_linked_entity *entry = list_entry(l, struct pslot_linked_entity, list);
		if (entry->flags == PSLOT_FLAGS_NEW)
		{
			int t = sprintf(string, "Task %d State %d", entry->pid,
					entry->state);
			printk(KERN_INFO "INFO %d %s", t, string);
			if (len + t < n)
			{
				memcpy(buffered + len, string, t);	
				len += t;
				entry->flags = PSLOT_FLAGS_OLD;
				/*list_del(l);
				  kfree(entry);*/
			}
			else
			{
				copy_to_user(u, buffered, len);
				return len;
			}
		}
	}
	copy_to_user(u, buffered, len);
	return len;
	return len;
}

static const struct file_operations proc_pslot_operations = {
	.read = pslot_read,
};

static int __init proc_pslot_init(void)
{
	struct proc_dir_entry *data = NULL;
	proc_file_entry = proc_create("pslot", 0, NULL, &proc_pslot_operations);
	return 0;
}
module_init(proc_pslot_init);
