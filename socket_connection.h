#ifndef SOCKET_CONNECTION
#define SOCKET_CONNECTION

#include <string.h>
#include <arpa/inet.h>

int socketConnection(int fd,int serverPort)
{
    int eStatus;
    struct sockaddr_in remote;
    memset(&remote, 0, sizeof remote);
    
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family = AF_INET;
    remote.sin_port = htons(serverPort);

    eStatus = connect(fd, (struct sockaddr *) &remote, sizeof(struct sockaddr_in));

    return eStatus;
}

#endif