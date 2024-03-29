#ifndef SOCKET_AND_BIND
#define SOCKET_AND_BIND

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int socket_and_bind_ipv4(void * port,int address_family, int socktype)
{
    struct addrinfo hints;
    struct addrinfo *res;
    struct addrinfo *p;
    int sockfd;
    int yes = 1;
    int status;

    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_NUMERICHOST;

    status = getaddrinfo(NULL,port,&hints,&res);
    if( status != 0)
    {
        return 11;
    }

    for(p = res, p!= NULL, p->ai_next)
    {
        sockfd = socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if(sockfd == -1)
        {
            continue
        }
        status = setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes);
        if(status != 0)
        {
            exit(1);
        }
        status = bind(sockfd, p->ai_addr, p->ai_addrlen);
        if( status == -1 )
        {
            
        }
    }
}

#endif
