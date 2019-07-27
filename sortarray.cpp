#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Merge(int *A,int lo,int mid,int hi)
{
    int temp[hi-lo+1];
    int i = lo, j = mid+1, k = 0;

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

    for(int i = lo; i<=hi; i++)
    {
        A[i] = temp[i-lo];
    }
}

void MergeSort(int *A,int lo,int hi)
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
    for(int j = p; j<=r-1; j++)
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

void ReverseSort(int arr[],int n)
{
    int i,j,idx;
    for(i=0; i<n-1; i++)
    {
        idx = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] > arr[idx])
                idx = j;
        }
        swap(arr[idx],arr[i]);
    }
}

void getArray(int *a,int n)
{
    //int tmp[n];

    srand( (unsigned)time( NULL ) );

    for (int i = 0; i < n; ++i)
    {
        a[i] = rand()%n;
        //cout << tmp[i] << endl;
    }
}

void copyArray(int *a,int *b,int n)
{
    for (int i = 0; i < n; ++i)
    {
        b[i] = a[i];
    }
}

int main()
{
    int choice, n,len=0;
    int *ma,*qa;

    clock_t t;
    double time_taken = 0.0;

    while(1)
    {
        printf("1. Generate average case\n");
        printf("2. Generate ascending case\n");
        printf("3. Generate descending case\n");
        printf("4. Apply Merge sort\n");
        printf("5. Apply Quicksort\n");
        printf("6. Print array\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Number of elements: ");
            scanf("%d", &n);
            len = n;
            // do yourself
            ma = new int[n];
            //qa = new int[n];
            getArray(ma,n);
           // copyArray(ma,qa,n);
            break;

        case 2:
            printf("Number of elements: ");
            scanf("%d", &n);
            // do yourself
            ma = new int[n];
            //qa = new int[n];
            getArray(ma,n);
           // copyArray(ma,qa,n);
            sort(ma,ma+n);
           // sort(qa,qa+n);
            break;

        case 3:
            printf("Number of elements: ");
            scanf("%d", &n);
            // do yourself
            ma = new int[n];
           // qa = new int[n];
            getArray(ma,n);
            //copyArray(ma,qa,n);
            ReverseSort(ma,n);
            //ReverseSort(qa,n);
            break;

        case 4:
        {
            printf("Applying merge sort\n");
            // do yourself
            // this should transform the given array into a sorted array
            auto start1 = chrono::high_resolution_clock::now();
            ios_base::sync_with_stdio(false);
            MergeSort(ma,0,n-1);
            auto end1 = chrono::high_resolution_clock::now();
            time_taken = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
            time_taken *= 1e-9;
            cout << "Time taken to finish :"  << fixed << setprecision(6) << time_taken*1e9 << " nanoseconds"  << endl;
        }
        break;

        case 5:
        {
            printf("Applying quicksort\n");
            // do yourself
            // this should transform the given array into a sorted array
            auto start2 = chrono::high_resolution_clock::now();
            ios_base::sync_with_stdio(false);
            QuickSort(ma,0,n-1);
            auto end2 = chrono::high_resolution_clock::now();
            time_taken = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
            time_taken *= 1e-9;
            cout << "Time taken to finish :"  << fixed << setprecision(6) << time_taken*1e9 << " nanoseconds"  << endl;
            //printf("Time taken to finish: <your time>\n");
        }
        break;

        case 6:
            printf("Array\n");
            // do yourself
            for(int i = 0; i<n; i++)
            {
                cout << ma[i] << " ";
            }
            cout << endl;
            break;
        }
    }
}

