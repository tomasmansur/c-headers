#ifndef IPV4_VALIDATOR_H_
#define IPV4_VALIDATOR_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


int check_ipv4(char *ip)
{
    int v; /* Valid or not. */
    char *octect; /* I mean "0-255", not prescise a octect like "10001110". */
    v = 1; /* At first we think the ipv4 address is valid, unless after checking not. */
    octect = strtok(ip,".");
    while(octect != NULL)
    {
        int n;
        n = atoi(octect);
        if( (n>255) || (n<0))
            v = 0;
        octect = strtok(NULL,".");
    }
    return v;
}

int validate_ipv4(char *ipv4)
{
    int r; /* result */
    check_ipv4(ipv4)? (r=1): (r=0);
    return r;
}

#endif /* IPV4_VALIDATOR_H_*/
