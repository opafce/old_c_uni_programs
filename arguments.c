#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, s = 0;
    for (i = 1; i < argc; i++)
        s += atoi(argv[i]);
    return s;
}
