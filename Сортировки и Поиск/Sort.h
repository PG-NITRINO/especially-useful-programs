#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED



#endif // SORT_H_INCLUDED

///Сортировка включением
void includesort(int *a, int n)
{
    int i,value,index;
    /// Для всех элементов кроме начального
    for(i=1; i<n; i++)
    {
        value=a[i]; /// запоминаем значение элемента
        index=i;   /// и его индекс
        while((index>0)&(a[index-1]>value)) /// >(от max до min) <(от min до max)
        {     /// смещаем другие элементы к концу массива пока они больше a[i]
            a[index]=a[index-1];
            index--;   /// смещаем просмотр к началу массива
        }
        a[index]=value; /// рассматриваемый элемент помещаем на освободившееся место
    }
}

///Сортировка выбором
void selectsort(int *a, int n)
{
    int i,j,min,d; /// для поиска минимального элемента и для обмена
    for(i=0; i<n-1; i++)
    {
        min=i; /// запоминаем индекс текущего элемента
    /// ищем минимальный элемент чтобы поместить на место i-ого
        for(j=i+1; j<n; j++)  /// для остальных элементов после i-ого
            if(a[j]<a[min]) /// если элемент меньше минимального,
                min=j;  /// >(от max до min) <(от min до max)
        d=a[min];    /// меняем местами i-ый и минимальный элементы
        a[min]=a[i];
        a[i]=d;
    }
}

///Сортировка обменом(метод пузырька)
void bubblesort(int *a, int n)
{
    int i,j,d;
    for(i=0; i<n-1; i++)
    {
        for(j=n-1; j>i; j--)
        {
            if(a[j]<a[j-1])
            {
                d=a[j];
                a[j]=a[j-1];
                a[j-1]=d;
            }
        }
    }
}

///Шейкер-сортировка(модифицированый пузырек(пузырек туда-сюда))
void shekersort(int *a, int n)
{
    int right=n-1,left=0,i,d;
    int flag=1; ///Есть перемещения
    while((flag>0)&(right>left))
    {
        flag=0;
        for(i=left; i<right; i++) ///слева направо
        {
            if(a[i]>a[i+1])
                {
                    d=a[i];
                    a[i]=a[i+1];
                    a[i+1]=d;
                    flag=1;  ///перемещение было
                }
        }
        right--;
        for(i=right; i>left; i--) ///справа налево
        {
            if(a[i]<a[i-1])
                {
                    d=a[i];
                    a[i]=a[i-1];
                    a[i-1]=d;
                    flag=1;
                }
        }
        left++;
    }
}

///Быстрая сортировка Хоара
void quicksort(int *a, int first, int last)
{
    int left=first, right=last;
    int d, x=a[(left+right)/2];

    do
    {
        while(a[left]<x)
            left++;
        while(a[right]>x)
            right--;
        if(left<=right)
        {
            if(left<right)
            {
                d=a[left];
                a[left]=a[right];
                a[right]=d;
            }
            left++;
            right--;
        }
    }while(left<=right);

    if(left<last)
        quicksort(a,left,last);
    if(first<right)
        quicksort(a,first,right);
}

 ///Сортировка слиянием
 int* margesort(int *a, int *buf, int left, int right)
 {
     if(left=right)///ввозможно надо ==
     {
         buf[left]=a[right];
         return(down);
     }
     int mid = (left+right)/2;

     ///Разделяй и влавствуй(сортируй)
     int *left_buf=margesort(up,down,left,mid);
     int *right_buf=margesort(up,down,mid+1,right);

     ///Слияние двух отсортированных половин
     int *target=left_buf==up?down:up;

     int left_cur=left,right_cur=mid+1, i;
     for(i=left; i<right; i++)
 }





