#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compare(int *i, int *j)
{
    if (memcmp(i, j, sizeof(*i)) == 0)
        printf("i和j相等\n");
    else
        printf("i和j不等\n");
}

int main(int argc, char *argv[])
{
    int i, j;
    printf("i = %d, j = %d\n", i, j);
    compare(&i, &j);
    memset(&i, 0, sizeof(i));
    printf("i = %d, j = %d\n", i, j);
    compare(&i, &j);
    memcpy(&j, &i, sizeof(i));
    printf("i = %d, j = %d\n", i, j);
    compare(&i, &j);
    exit(0);
}