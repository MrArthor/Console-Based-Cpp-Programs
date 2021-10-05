#include<iostream>
using namespace std;

//Bubble Sort

void Bubblesort(int A[],int n)
{ 
    int temp;
    int flag=0;
    for (int i = 0; i < n ; i++)
    {
        flag=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if (flag==0)
        {
            break;
        }
        
        
    }

    
    cout<<"\n\nAfter Sorting, The Elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
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

    Bubblesort(A,n);

    return 0;
}