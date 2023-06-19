#include <stdio.h>
//copyright by Ivan Ivanin from 23.11.2017 17:29

int main(int argc, char *argv[], char *envp[])
{
    int i;
    for (i = 0; envp[i]; i++)
        puts(envp[i]);
    return 0;
}

