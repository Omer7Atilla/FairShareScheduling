#include <linux/set_fss_flag.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <asm/uaccess.h>
#include <asm/system.h>

asmlinkage int sys_set_fss_flag(int *data)
{
	int flag;
	long failed_bytes;
	int return_code = -1;
	
	failed_bytes = copy_from_user(&flag, data, sizeof(int));

	if(failed_bytes) return return_code;

	if(flag != 0 && flag != 1) return return_code;

	fss_flag = flag;


	return 0;

}
