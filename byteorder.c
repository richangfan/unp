/**
 * 查看主机字节序
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    union
    {
        short s;
        char c[sizeof(short)];
    } un;
    un.s = 0x0102;

    if (sizeof(short) != 2)
        printf("短整形变量不是16位\n"), exit(1);
    if (un.c[0] == 1 && un.c[1] == 2)
        printf("大端字节序\n");
    else if (un.c[0] == 2 && un.c[1] == 1)
        printf("小端字节序\n");
    else
        printf("无法判断\n");
    return 0;
}