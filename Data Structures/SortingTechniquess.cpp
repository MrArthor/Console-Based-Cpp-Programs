#include<iostream>
using namespace std;

//Bubble Sort

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Bubblesort(int A[],int n)
{ 
    int temp;
    for (int i = 0; i < n-1 ; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
        
    }

    
    cout<<"\n\nAfter Sorting, The Elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    
}

//Insertion Sort 

void InsertionSort(int A[], int n)
{
    int x,j;
    for(int i=1 ; i<n ; i++)
    {
        j=i-1;
        x=A[i];

        while(A[j]>x && j>-1)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }

    cout<<"\n\nAfter Sorting, The Elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }

}

//Selection Sort 

void SelectionSort(int A[], int n)
{
    int i,j,k,temp;

    for( i=0 ; i<n ; i++)
    {
        for ( j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k=j;
            }
        }
        temp=A[i];
        A[i]=A[k];
        A[k]=temp;      
    }

    cout<<"\n\nAfter Sorting, The Elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
}

//Quick Sort

int Partition(int A[], int startIndex, int endIndex)
{
    int pivot = A[endIndex];
    int pIndex = startIndex;

    for(int i=startIndex ; i<(endIndex-1) ; i++)
    {
        if(A[i] <= pivot)
        {
            int temp1 = A[i];
            A[i] = A[pIndex];
            A[pIndex] = temp1;

            pIndex++;
        }
    }

    int temp2 = A[endIndex];
    A[endIndex] = A[pIndex];
    A[pIndex] = temp2;

    return pIndex;
}

void Quicksort(int A[], int startIndex, int endIndex)
{
    if(startIndex < endIndex)
    {
        int p = Partition(A,startIndex,endIndex);
        Quicksort(A,startIndex,(p-1));       //recursive call for left partition
        Quicksort(A,(p+1),endIndex);       //recursive call for right partition
    }
}

//Merge Sort

void Merge(int arr[],int l,int m,int r)
{
    int i=l;
    int j=m+1;
    int k=l;

    int size=(r-1)+1;
    int temp[size];

    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }

        else
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }

    while(i<=m)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }

    while(j<=r)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }

    for(int s=l;s<=r;s++)
    {
        arr[s]=temp[s];
    }


}

void MergeSort(int ARR[],int l, int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        MergeSort(ARR,l,m);
        MergeSort(ARR,m+1,r);
        Merge(ARR,l,m,r);
    }
    
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int A[n];
    cout<<"\n\nEnter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }

    Quicksort(A,0,(n-1));

    cout<<"\n\nAfter Sorting, The Elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}
