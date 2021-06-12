#include <iostream>
using namespace std;

template <class T>
void swap(T *a, T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
}
template <class T>
void Merge(T Arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    T L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = Arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = Arr[m + 1 + j];

    int i = 0;

    int j = 0;

    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            Arr[k] = L[i];
            i++;
        }
        else
        {
            Arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        Arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        Arr[k] = R[j];
        j++;
        k++;
    }
}
template <class T>
void MergeSort(T Arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    MergeSort(Arr, l, m);
    MergeSort(Arr, m + 1, r);
    Merge(Arr, l, m, r);
}
template <class T>
void BubbleSort(T Arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (Arr[j] > Arr[j + 1])
                swap(&Arr[j], &Arr[j + 1]);
}
template <class T>
int partition(T Arr[], int low, int high)
{
    int pivot = Arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (Arr[j] < pivot)
        {
            i++;
            swap(&Arr[i], &Arr[j]);
        }
    }
    swap(&Arr[i + 1], &Arr[high]);
    return (i + 1);
}
template <class T>
int QuickSort(T Arr[], int low, int high)
{

    {
        if (low < high)
        {

            int pi = partition(Arr, low, high);

            QuickSort(Arr, low, pi - 1);
            QuickSort(Arr, pi + 1, high);
        }
    }
}
template <class T>
void selectionSort(T arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}


template <class T>
class Sort
{
public:
    friend int QuickSort(T Arr[], int low, int high);
    friend int MergeSort(T Arr[], int l, int r);
    friend int BubleSort(T Arr[], int n);
};
int main()
{
    cout << "Hello Death";
    return 0;
}
