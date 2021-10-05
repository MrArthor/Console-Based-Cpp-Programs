#include<iostream>
using namespace std;

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
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int arr[size];
    cout<<"\nEnter"<<size<<" elements of the array: ";
    
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    cout<<"\nBefore the Merge Sort: ";
    
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    MergeSort(arr,0,size-1);

    cout<<"\nAfter the Merge Sort: ";
    
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }


}