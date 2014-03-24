#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
/*
extern const struct seq_operations cpuinfo_op;
static int cpuinfo_open(struct inode *inode, struct file *file)
{
	return seq_open(file, &cpuinfo_op);
}

static const struct file_operations proc_cpuinfo_operations = {
	.open		= cpuinfo_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= seq_release,
};
*/

struct proc_dir_entry	*proc_file_entry;

static ssize_t pslot_read(struct file* f, char __user* u , size_t n, loff_t *o)
{
printk(KERN_INFO "You are trying to read something here");
	return 0;
}

static const struct file_operations proc_pslot_operations = {
	.read = pslot_read,
};

static int __init proc_pslot_init(void)
{
	proc_create("pslot", 0, NULL, &proc_pslot_operations);
	return 0;
}
module_init(proc_pslot_init);
