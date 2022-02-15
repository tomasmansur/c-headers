#ifndef BIND_CREATED_SOCKET
#define BIND_CREATED_SOCKET

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

int bindCreatedSocket(int fd, int port)
{
    int eStatus;
    struct sockaddr_in server;
    memset(&server, 0, sizeof server);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl("127.0.0.1");
    server.sin_port = htons(port);

    eStatus = bind(fd,(struct sockaddr *) &server, sizeof(server));

    return eStatus;
}

#endif