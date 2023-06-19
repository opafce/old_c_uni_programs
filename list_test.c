#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 150

int main()
{
    List *list = NULL;
    unsigned ji, p;
    srand((unsigned)time(NULL));
    p = rand() % N;
    for (ji = p; ji > 0; ji--) {
        if (ji % 2 == 1)
            list = list_append(list, ji);
        else 
            list = list_add(list, ji);
    }
    if (list_get(list, p) == -1)
        puts("OK");
    else
        puts("FAIL");
    list_destroy(list);
return 0;
}
