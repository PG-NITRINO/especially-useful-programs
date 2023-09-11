#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

#include "Sort.h"
#include "Search.h"

int compare(const void *x1, const void *x2)
{
    return(*(int*)x1-*(int*)x2);
}

int main()
{
    setlocale(LC_ALL,"Rus");
    const int n=83;
    int mas[n];
    int i,c;
    srand(time(0));
    for(i=0; i<n; i++)
    {
        mas[i]=rand()%1000;
        //printf("%5.3i",mas[i]);
    }

    ///Разные сортировки
    //includesort(mas,n); ///Включением
    //selectsort(mas,n);  ///Выбором
    //bubblesort(mas,n);  ///Пузырьковая
    //shekersort(mas,n);  ///Шейкер
    //quicksort(mas,0,n); ///Быстрая
    qsort(mas, n, 4, compare);  ///Встроенная функция(по сути быстрая сортировка)

    printf("\n\n");
    for(i=0; i<n; i++)
        printf("%5.3i",mas[i]);  ///Вывод отсортированного массива

    printf("\n\nИскомое число:"); ///Какое число нужно найти в отсортированном массиве
    scanf("%i",&c);

    ///Поиск в массиве
    //i=indexsearch(mas,n,c);  ///Индексный
    i=binarsearch(mas,0,n,c);  ///Бинарный

    if(i==-1)
        printf("Такого числа нет...");
    else
        printf("Число %i располагается под номером: %i",c,i+1);

    return 0;
}
