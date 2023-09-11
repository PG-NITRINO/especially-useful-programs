#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

/*char *wday[] = {"Воскресенье","Понедельник","Вторник",
                "Среда","Четверг","Пятница","Суббота",
                "Неизвестен"};*/
void delay(int ms)
{
    int c=clock()+ms;
    while(clock()<c);
}

int main()
{
    setlocale(LC_ALL,"Rus");
   /* struct tm time_check;
   int year,month,day;
   // для нахождения дня недели, необходимо ввести день, месяц и год
   printf("Год:  ");
   scanf("%d",&year);
   printf("Месяц:  ");
   scanf("%d",&month);
   printf("День:  ");
   scanf("%d",&day);
   // занести данные в структуру time_check
   time_check.tm_year = year -1900;
   time_check.tm_mon = month - 1;
   time_check.tm_mday = day;
   time_check.tm_hour = 0;
   time_check.tm_min = 0;
   time_check.tm_sec = 0;
   time_check.tm_isdst = -1;
   // для заполнения оставшихся полей вызвать mktime
   if(mktime(&time_check) == -1)
       time_check.tm_wday = 7;
   // вывести день недели
   printf("Это был: %s\n",wday[time_check.tm_wday]);*/
    struct tm infotime;

    /*time_t start1=time(NULL);

    clock_t start2=clock();
    int i;
    for(i=0; i<1245; i++)
    {
        printf("%i\n",i);
    }

    time_t end1=time(NULL);

    clock_t end2=clock();

    printf("Время работы в секундах:%ld\n",(end2/CLOCKS_PER_SEC)-(start2/CLOCKS_PER_SEC));
    printf("Время работы в тиках процессора:%i или %3.3f секунд\n",(int)(end2-start2),((float)(end2-start2))/1000);

    printf("Время работы:%3.2f\n",difftime(end1,start1));
    printf("Время работы(тоже самое):%i\n",(int)(end1-start1));*/
   infotime.tm_year = 1970 -1900;
   infotime.tm_mon = 0;
   infotime.tm_mday = 1;
   infotime.tm_hour = 20;
   infotime.tm_min = 0;
   infotime.tm_sec = 0;
   infotime.tm_isdst = -1;

   //Возвращает кол-во секунд с 1 января 1970 по введенную дату(с погрешностью)
   printf("С 1 января 1970 года прошло %i секунд\n",(int)mktime(&infotime));
   printf("Hорм дата: %s",asctime(&infotime));
   const time_t t=time(NULL);
   printf("Present date: %s",ctime(&t));

   time_t T;
   struct tm *gm;
   T=time(NULL);
   gm=gmtime(&T);
   printf("Время по Гринвичу: %s",asctime(gm));

   struct tm *local;
   time(&T);
   local=localtime(&T);
   printf("Local date: %s",asctime(local));

   char str[80];
   strftime(str,80,"Сейчас %j день в году",local);
   printf("%s",str);

   T=clock();
   printf("\nДо delay %i\n",(int)T);
   delay(1000);
   T=clock();
   printf("\nПосле delay %i\n",(int)T);

    return 0;
}
