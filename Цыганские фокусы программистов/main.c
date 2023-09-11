///Цыганские фокусы программистов(Gypsy tricks of programmers), при поддержке Хауди Хо
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

    {/*№1 Проверка на четность с помощью побитового И (&)*/
    int a;
    printf("Введите число:");
    scanf("%i",&a);
    if((a&1)==0) printf("Число %i четное\n",a);
    else/*if((a&1)==1)*/ printf("Число %i нечетное\n",a);
    }

    {/*№2 Обмен значений переменных с помощью побитового исключающего ИЛИ (XOR)*/
        int x=-5,y=10;
        printf("\nИтак, x равен %i, y равен %i\n",x,y);
        printf("Magic...\n");
        x=x^y;
        y=x^y;
        x=x^y;
        printf("Теперь x равен %i, y равен %i\n",x,y);
    }

    {/*Применение enum*/

     printf("\nСейчас будем выводить числа... Готов?\n");
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
