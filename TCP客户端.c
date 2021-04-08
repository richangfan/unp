#include "tcp.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd;
    const int MAX_CLIENT = 10;
    const char *ip = "127.0.0.1";
    const int port = 4444;
    struct sockaddr_in sa4_server;
    socklen_t len;

    init_sockaddr(&sa4_server, ip, port);
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1)
        printf("TCP套接字创建失败\n"), error_exit();
    len = sizeof(sa4_server);
    if (connect(sockfd, (struct sockaddr *)&sa4_server, len) == -1)
        printf("连接服务端失败\n"), error_exit();
    exit(0);
}