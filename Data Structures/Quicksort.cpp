#include<iostream>
using namespace std;

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