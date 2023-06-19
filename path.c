#include <stdio.h>
#include <string.h>
//copyright by Ivan Ivanin from 23.11.2017 17:38

int main(int argc, char *argv[], char *envp[])
{
    int i;
    for (i = 0; envp[i]; i++)
    {
        if (strncmp(envp[i], "PATH=", 5) == 0)
        {
            puts(envp[i] + 5);
            break;
        }
    }
    return 0;
}
