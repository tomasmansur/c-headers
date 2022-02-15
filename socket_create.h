#ifndef SOCKET_CREATE
#define SOCKET_CREATE

#include <sys/types.h>
#include <sys/socket.h>

short socketCreate(void)
{
    int hSocket;
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

#endif
