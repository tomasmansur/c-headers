#ifndef RETURN_KERNEL_VERSION
#define RETURN_KERNEL_VERSION

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * return_kernel_version()
{
    int fd_proc_version;
    int times;
    int lseek_status;
    void * ch;
    void * chars;
    void * kernel_version_string;
    
    chars = "0123456789.";
    fd_proc_version = open("/proc/version",O_RDONLY);
    if(fd_proc_version == -1)
    {
        exit(1);
    }
    
    /* Next we go to the char (space) before the x.x.x kernel version */
    kernel_version_string = malloc(9);
    times = 0;
    while(times < 3)
    {
        do
        {
            lseek_status = lseek(fd_proc_version,1,SEEK_CUR);
            if(lseek_status == -1)
            {
                abort();
            }
            read(fd_proc_version,ch,1);
            /* in case we are in the second space char. */
            if(times == 2)
            {
                strncpy(kernel_version_string,ch,1);
            }
        } while (ch != " ");
        times = times + 1;
    }

    close(fd_proc_version);
    return kernel_version_string;
}

#endif
