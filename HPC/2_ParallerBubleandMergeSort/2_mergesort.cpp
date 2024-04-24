#include <iostream>
#include <omp.h>
using namespace std;

void mergeAll(int arr[], int s, int mid, int e)
{
    int n1 = mid - s + 1;
    int n2 = e - mid;
    int temp1[n1];
    int temp2[n2];

    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[s + i];
    }

    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = s;

    while (i < n1 && j < n2)
    {
        if (temp1[i] < temp2[j])
        {
            arr[k] = temp1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = temp2[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = temp1[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = temp2[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    #pragma omp parallel sections
    {
        # pragma omp section
        mergeSort(arr, s, mid);

        #pragma omp section
        mergeSort(arr, mid + 1, e);
    }

    mergeAll(arr, s, mid, e);
}

int main()
{
    int arr[] = {3, 2, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
