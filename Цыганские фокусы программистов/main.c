///��������� ������ �������������(Gypsy tricks of programmers), ��� ��������� ����� ��
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum numbers
{
    one=1,
    two,
};

int main()
{
    setlocale(LC_ALL,"Rus");

    {/*�1 �������� �� �������� � ������� ���������� � (&)*/
    int a;
    printf("������� �����:");
    scanf("%i",&a);
    if((a&1)==0) printf("����� %i ������\n",a);
    else/*if((a&1)==1)*/ printf("����� %i ��������\n",a);
    }

    {/*�2 ����� �������� ���������� � ������� ���������� ������������ ��� (XOR)*/
        int x=-5,y=10;
        printf("\n����, x ����� %i, y ����� %i\n",x,y);
        printf("Magic...\n");
        x=x^y;
        y=x^y;
        x=x^y;
        printf("������ x ����� %i, y ����� %i\n",x,y);
    }

    {/*���������� enum*/

     printf("\n������ ����� �������� �����... �����?\n");
     int i;
     for (i=1; i<7; i++)
        switch(i)
     {
         case one: printf("1"); break;
         case two: printf("2"); break;
     };

    }

    {/**/
    }
    return 0;
}
