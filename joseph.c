#include <stdio.h>
#include <stdlib.h>

// copyright by Ivan Ivanin from 23.11.2017 22:45
int main()
{
    int i = 0, n, m, fm, fn; // условие первого ппрохода цикла
    int *p = NULL; // указатель
    scanf("%d%d", &n, &m); //вводь двух чисел из условия
    p = (int*) malloc(n * sizeof(int)); //дитнамическое выделение памяти
    for (i = 0; i < n; i++) // цикл присвоения всем элементам массива 1
        p[i] = 1;
    fm = m; // изменяющаяся м в цикле
    i = m - 1; // счетчик который ходит по циклу
    fn = n; // счетчик игроков
    while (fn > 0) // цикл пока есть игроки
    {
        while (p[i % n] == 0)
            i++;
        if (fm % m == 0)
        {
            p[i% n] = 0;
            if(fn <= 3)
                printf("%d ", i % n + 1);
            fn--;
        }
        i++;
        fm++;
    }
    free(p);
    return 0;
}
