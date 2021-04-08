#include <stdio.h>
#include <stdlib.h>

void printenv(const char *s)
{
    char *p = getenv(s);
    if (p != NULL)
        printf("%s等于%s\n", s, p);
}

int main(int argc, char *argv[])
{
    printenv("PWD");
    printenv("LISTENQ");
    exit(0);
}