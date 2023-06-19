#include <stdio.h>
#include <string.h>
//copyright by Ivan Ivanin from 23.11.2017 19:07

int main(int argc, char *argv[], char *envp[])
{
    int i, j;
    for (i = 0; envp[i]; i++)
    {
        if (strncmp(envp[i], "PATH=", 5) == 0)
        {
            for (j = 5; envp[i][j]; j++)
            {
                if (envp[i][j] != ':')
                    printf("%c", envp[i][j]);
                else
                    printf("\n");
            }
            break;
        }
    }
    return 0;
}
