#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED



#endif // SEARCH_H_INCLUDED

///»ндексно-последовательный поиск
int indexsearch(int *a, int n, int key)
{
    int i,j,i1,flag=1;
    for(i=7, j=0; (i<n)&(flag=1); i=i+8, j=j+8)
    {
        if((i<n)&(a[i]>key))
        {
            flag=0;
            for(i1=j; i1<=i; i1++)
            {
                if(a[i1]==key) return(i1);
            }
            return(-1);
        }
    }
    for(i1=i-8; i1<n; i1++)
    {
        if(a[i1]==key) return(i1);
    }
    return(-1);
}

///Ѕинарный поиск(метод дихотомии, делени€ отрезка пополам)
int binarsearch(int *a, int left, int right, int key)
{
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(a[mid]==key)
        {
            return(mid);
        }
        if(a[(mid)]>key) right=mid-1;
        if(a[(mid)]<key) left=mid+1;
    }
    return(-1);
}
