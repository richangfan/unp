#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error_exit()
{
    switch (errno)
    {
    case EACCES:
        printf("The address is protected, and the user is not the superuser.\n");
        break;
    case EADDRINUSE:
        printf("The given address is already in use.\n");
        break;
    case EBADF:
        printf("sockfd is not a valid file descriptor.\n");
        break;
    case EINVAL:
        printf("The socket is already bound to an address.\n");
        break;
    case ENOTSOCK:
        printf("The file descriptor sockfd does not refer to a socket.\n");
        break;
    default:
        break;
    }
    exit(1);
}