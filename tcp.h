#include "common.h"
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void init_sockaddr(struct sockaddr_in *sa4, const char *ip, const int port)
{
    memset(sa4, 0, sizeof(*sa4));
    sa4->sin_family = AF_INET;
    sa4->sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &(sa4->sin_addr)) != 1)
        printf("转换IPv4地址失败\n"), exit(1);
}