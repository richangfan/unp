#include "tcp.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd;
    const int MAX_CLIENT = 10;
    const char *ip = "127.0.0.1";
    const int port = 4444;
    struct sockaddr_in sa4;

    init_sockaddr(&sa4, ip, port);
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1)
        printf("TCP套接字创建失败\n"), error_exit();
    if (bind(sockfd, (struct sockaddr *)&sa4, sizeof(sa4)) == -1)
    {
        printf("绑定端口失败\n");
        if (close(sockfd) == -1)
            printf("关闭套接字失败\n");
        error_exit();
    }
    if (listen(sockfd, MAX_CLIENT) == -1)
        printf("监听失败\n"), error_exit();
    while (1)
    {
        struct sockaddr_in sa4_client;
        int confd;
        socklen_t len;
        char buff[32];
        pid_t pid;

        memset(&sa4_client, 0, sizeof(sa4_client));
        len = sizeof(sa4_client);
        confd = accept(sockfd, (struct sockaddr *)&sa4_client, &len);
        if (confd == -1)
            printf("接受客户端连接失败\n"), error_exit();
        pid = fork();
        if (pid == 0)
        {
            printf("子进程ID为%d\n", getpid());
            printf("客户端IP为%s\n", inet_ntop(AF_INET, &(sa4_client.sin_addr), buff, sizeof(buff)));
            printf("客户端端口为%d\n", ntohs(sa4_client.sin_port));
            if (shutdown(confd, SHUT_RDWR) == -1)
                printf("关闭连接失败\n"), error_exit();
            if (close(confd) == -1)
                printf("关闭套接字失败\n"), error_exit();
            exit(0);
        }
        else
        {
            if (close(confd) == -1)
                printf("关闭套接字失败\n"), error_exit();
        }
    }
    exit(0);
}