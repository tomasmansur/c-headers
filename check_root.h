#ifndef CHECK_ROOT
#define CHECK_ROOT

#define GLIBC_VERSION (__GLIBC_MINOR__)

#if GLIBC_VERSION > 19
    #define _POSIX_C_SOURCE 2
#elif GLIBC_VERSION <= 19
    #define _DEFAULT_SOURCE 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

/*
Return 0 if you are root.
*/
int check_root_(void)
{
    FILE *fp;
    char user[N];

    fp = popen("whoami","r"); /* Unix */
    if( fp == NULL)
    {
        exit(1);
    }
    fgets(user,N,fp);
    pclose(fp);

    if( strncmp(user,"root",N) )
        return 1;
    else
        return 0;
}

#endif
