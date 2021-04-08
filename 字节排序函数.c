#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    unsigned short port = 10086;
    unsigned int ip = 0x0fff0000;
    printf("主机字节序：\n");
    printf("port等于%d\n", port);
    printf("ip等于%d\n", ip);
    printf("网络字节序：\n");
    printf("port等于%d\n", htons(port));
    printf("ip等于%d\n", htonl(ip));
    exit(0);
}