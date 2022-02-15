#ifndef RESOLVE_HOSTNAME_ADDRINFO
#define RESOLVE_HOSTNAME_ADDRINFO

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

/*
1st arg is hostname to resolve via getaddrinfo(3).
2nd arg address family.
3rd arg pointer to store ipv4/6 in char type.
return value: zero if success, case of error or something NULL.
*/
int resolve_hostname_getaddrinfo(void * the_hostname,int address_family,void * ip_str)
{
    struct addrinfo hints;
    struct addrinfo *results;
    struct addrinfo *p;
    /* filing up hints structure */
    memset(&hints,0,sizeof(hints));
    hints.ai_family = address_family;
    hints.ai_socktype = SOCK_STREAM;
    if( getaddrinfo(the_hostname,NULL,&hints,&results) != 0)
    {
         return 77;
    }
    /* getting the ip address of hostname */
    for(p = results ; p != NULL ; p = p->ai_next)
    {
        if( p->ai_family == address_family)
        {
            inet_ntop(address_family,&(((struct sockaddr_in *)p->ai_addr)->sin_addr),ip_str,INET_ADDRSTRLEN);
            break;
        }
        
    }
    if(p == NULL)
    {
        return 88;
    }
    freeaddrinfo(results);
    return 0;
}

#endif