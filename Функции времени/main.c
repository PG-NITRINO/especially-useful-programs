#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

/*char *wday[] = {"�����������","�����������","�������",
                "�����","�������","�������","�������",
                "����������"};*/
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
   // ��� ���������� ��� ������, ���������� ������ ����, ����� � ���
   printf("���:  ");
   scanf("%d",&year);
   printf("�����:  ");
   scanf("%d",&month);
   printf("����:  ");
   scanf("%d",&day);
   // ������� ������ � ��������� time_check
   time_check.tm_year = year -1900;
   time_check.tm_mon = month - 1;
   time_check.tm_mday = day;
   time_check.tm_hour = 0;
   time_check.tm_min = 0;
   time_check.tm_sec = 0;
   time_check.tm_isdst = -1;
   // ��� ���������� ���������� ����� ������� mktime
   if(mktime(&time_check) == -1)
       time_check.tm_wday = 7;
   // ������� ���� ������
   printf("��� ���: %s\n",wday[time_check.tm_wday]);*/
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

    printf("����� ������ � ��������:%ld\n",(end2/CLOCKS_PER_SEC)-(start2/CLOCKS_PER_SEC));
    printf("����� ������ � ����� ����������:%i ��� %3.3f ������\n",(int)(end2-start2),((float)(end2-start2))/1000);

    printf("����� ������:%3.2f\n",difftime(end1,start1));
    printf("����� ������(���� �����):%i\n",(int)(end1-start1));*/
   infotime.tm_year = 1970 -1900;
   infotime.tm_mon = 0;
   infotime.tm_mday = 1;
   infotime.tm_hour = 20;
   infotime.tm_min = 0;
   infotime.tm_sec = 0;
   infotime.tm_isdst = -1;

   //���������� ���-�� ������ � 1 ������ 1970 �� ��������� ����(� ������������)
   printf("� 1 ������ 1970 ���� ������ %i ������\n",(int)mktime(&infotime));
   printf("H��� ����: %s",asctime(&infotime));
   const time_t t=time(NULL);
   printf("Present date: %s",ctime(&t));

   time_t T;
   struct tm *gm;
   T=time(NULL);
   gm=gmtime(&T);
   printf("����� �� ��������: %s",asctime(gm));

   struct tm *local;
   time(&T);
   local=localtime(&T);
   printf("Local date: %s",asctime(local));

   char str[80];
   strftime(str,80,"������ %j ���� � ����",local);
   printf("%s",str);

   T=clock();
   printf("\n�� delay %i\n",(int)T);
   delay(1000);
   T=clock();
   printf("\n����� delay %i\n",(int)T);

    return 0;
}
