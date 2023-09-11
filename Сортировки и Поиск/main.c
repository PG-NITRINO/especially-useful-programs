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

    ///������ ����������
    //includesort(mas,n); ///����������
    //selectsort(mas,n);  ///�������
    //bubblesort(mas,n);  ///�����������
    //shekersort(mas,n);  ///������
    //quicksort(mas,0,n); ///�������
    qsort(mas, n, 4, compare);  ///���������� �������(�� ���� ������� ����������)

    printf("\n\n");
    for(i=0; i<n; i++)
        printf("%5.3i",mas[i]);  ///����� ���������������� �������

    printf("\n\n������� �����:"); ///����� ����� ����� ����� � ��������������� �������
    scanf("%i",&c);

    ///����� � �������
    //i=indexsearch(mas,n,c);  ///���������
    i=binarsearch(mas,0,n,c);  ///��������

    if(i==-1)
        printf("������ ����� ���...");
    else
        printf("����� %i ������������� ��� �������: %i",c,i+1);

    return 0;
}
