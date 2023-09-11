#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED



#endif // SORT_H_INCLUDED

///���������� ����������
void includesort(int *a, int n)
{
    int i,value,index;
    /// ��� ���� ��������� ����� ����������
    for(i=1; i<n; i++)
    {
        value=a[i]; /// ���������� �������� ��������
        index=i;   /// � ��� ������
        while((index>0)&(a[index-1]>value)) /// >(�� max �� min) <(�� min �� max)
        {     /// ������� ������ �������� � ����� ������� ���� ��� ������ a[i]
            a[index]=a[index-1];
            index--;   /// ������� �������� � ������ �������
        }
        a[index]=value; /// ��������������� ������� �������� �� �������������� �����
    }
}

///���������� �������
void selectsort(int *a, int n)
{
    int i,j,min,d; /// ��� ������ ������������ �������� � ��� ������
    for(i=0; i<n-1; i++)
    {
        min=i; /// ���������� ������ �������� ��������
    /// ���� ����������� ������� ����� ��������� �� ����� i-���
        for(j=i+1; j<n; j++)  /// ��� ��������� ��������� ����� i-���
            if(a[j]<a[min]) /// ���� ������� ������ ������������,
                min=j;  /// >(�� max �� min) <(�� min �� max)
        d=a[min];    /// ������ ������� i-�� � ����������� ��������
        a[min]=a[i];
        a[i]=d;
    }
}

///���������� �������(����� ��������)
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

///������-����������(��������������� �������(������� ����-����))
void shekersort(int *a, int n)
{
    int right=n-1,left=0,i,d;
    int flag=1; ///���� �����������
    while((flag>0)&(right>left))
    {
        flag=0;
        for(i=left; i<right; i++) ///����� �������
        {
            if(a[i]>a[i+1])
                {
                    d=a[i];
                    a[i]=a[i+1];
                    a[i+1]=d;
                    flag=1;  ///����������� ����
                }
        }
        right--;
        for(i=right; i>left; i--) ///������ ������
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

///������� ���������� �����
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

 ///���������� ��������
 int* margesort(int *a, int *buf, int left, int right)
 {
     if(left=right)///��������� ���� ==
     {
         buf[left]=a[right];
         return(down);
     }
     int mid = (left+right)/2;

     ///�������� � ���������(��������)
     int *left_buf=margesort(up,down,left,mid);
     int *right_buf=margesort(up,down,mid+1,right);

     ///������� ���� ��������������� �������
     int *target=left_buf==up?down:up;

     int left_cur=left,right_cur=mid+1, i;
     for(i=left; i<right; i++)
 }





