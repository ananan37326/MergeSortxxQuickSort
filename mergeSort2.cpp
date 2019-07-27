#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Merge(int A[],int lo,int mid,int hi)
{
    int temp[hi-lo+1];
    int i = lo, j = mid+1 , k = 0;

    while(i<=mid && j<=hi)
    {
        if(A[i]<=A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while(i<=mid)
        temp[k++] = A[i++];

    while(j<=hi)
        temp[k++] = A[j++];

    for(int i = lo;i<=hi;i++)
    {
        A[i] = temp[i-lo];
    }
}

void MergeSort(int A[],int lo,int hi)
{
    if(lo<hi)
    {
        int mid = (lo+hi)/2;

        MergeSort(A,lo,mid);
        MergeSort(A,mid+1,hi);

        Merge(A,lo,mid,hi);
    }
}

int Partition(int *A,int p,int r)
{
    int x = A[r];
    int i = p-1;
    for(int j = p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void QuickSort(int *A,int p,int r)
{
    if(p<r)
    {
        int q = Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

int main()
{
    srand(time(NULL));
    int a[20];
    for(int i=0; i<20; i++)
    {
        a[i] = rand()%100;
    }

    cout << "Before Sorting : ";
    for(int i=0; i<20; i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;

    QuickSort(a,0,19);

    cout << "After Sorting : ";
    for(int i=0; i<20; i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;
    return 0;
}
