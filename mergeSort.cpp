#include<iostream>
#define NULL_VALUE -999999
#define INFINITY 999999

using namespace std;

void Merge(int A[],int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int i,j,k;

    int L[n1],R[n2];

    for(int i=0; i<n1; i++)
    {
        L[i] = A[p+i];
    }

    for(int j=0; j<n2; j++)
    {
        R[j] = A[q+j+1];
    }

    //L[n1] = INFINITY;
   // R[n2] = INFINITY;

    i = 0;
    j = 0;
    k = p;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q = p + (r-1)/2;

        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

int main()
{
    srand(0);
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

    MergeSort(a,0,20);

    cout << "After Sorting : ";
    for(int i=0; i<20; i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;

    return 0;
}
