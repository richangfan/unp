#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>

void printsockaddr(struct sockaddr *sa)
{
    char addr[128];
    if (sa->sa_family == AF_INET)
    {
        struct sockaddr_in *sa4 = (struct sockaddr_in *)sa;
        if (inet_ntop(AF_INET, &(sa4->sin_addr), addr, 32) != NULL)
        {
            printf("套接字版本为IPv4，目标地址是%s，目标端口号是%d\n", addr, ntohs(sa4->sin_port));
            return;
        }
        else
            printf("转换二进制IPv4地址失败\n");
    }
    else if (sa->sa_family == AF_INET6)
    {
        struct sockaddr_in6 *sa6 = (struct sockaddr_in6 *)sa;
        if (inet_ntop(AF_INET6, &(sa6->sin6_addr), addr, 128) != NULL)
        {
            printf("套接字版本为IPv6，目标地址是%s，目标端口号是%d\n", addr, ntohs(sa6->sin6_port));
            return;
        }
        else
            printf("转换二进制IPv6地址失败\n");
    }
    else
    {
        printf("不支持的IP地址族\n");
    }
    if (errno == EAFNOSUPPORT)
        printf("错误码表示不支持的IP地址族\n");
    else if (errno == ENOSPC)
        printf("错误码表示缓冲变量长度太小\n");
}

int main(int argc, char *argv[])
{
    int error;
    //IPv4地址结构体
    struct sockaddr_in sa4;
    //IPv6地址结构体
    struct sockaddr_in6 sa6;

    memset(&sa4, 0, sizeof(sa4));
    sa4.sin_family = AF_INET;
    sa4.sin_port = htons(4444);
    if (inet_pton(AF_INET, "127.0.0.1", &sa4.sin_addr) != 1)
        printf("转换IPv4地址失败\n"), exit(1);
    printsockaddr((struct sockaddr *)&sa4);

    memset(&sa6, 0, sizeof(sa6));
    sa6.sin6_family = AF_INET6;
    sa6.sin6_port = htons(6666);
    if (inet_pton(AF_INET6, "0:0:0:0:0:0:0:1", &sa6.sin6_addr) != 1)
        printf("转换IPv6地址失败\n"), exit(1);
    printsockaddr((struct sockaddr *)&sa6);

    exit(0);
}