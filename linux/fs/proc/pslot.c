#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#include "internal.h"

#include <linux/sched.h>

struct proc_dir_entry	*proc_file_entry;

static ssize_t pslot_read(struct file* f, char __user* u , size_t n, loff_t *o)
{
	printk(KERN_INFO "Read some stuff here but no.\n");
	struct list_head *l = NULL;
	list_for_each(l, &init_pslot_list)
	{
		struct pslot_linked_entity *entry = list_entry(l, struct pslot_linked_entity, list);
		printk(KERN_INFO "Task = %d", entry->task->pid);
	}
	return 0;
}

static const struct file_operations proc_pslot_operations = {
	.read = pslot_read,
};

static int __init proc_pslot_init(void)
{
	struct proc_dir_entry *data = NULL;
	proc_file_entry = proc_create("pslot", 0, NULL, &proc_pslot_operations);
	printk(KERN_WARNING "tititoto proc %s\n", proc_file_entry->parent->name);

	data = proc_root.parent;
	for (; data != NULL; data = data->next)
	{
		printk(KERN_INFO "toto %s\n", data->name);
		if (strcmp(data->name, "pslot") == 0)
			printk(KERN_INFO "FIND IT\n");
	}

	return 0;
}
module_init(proc_pslot_init);
