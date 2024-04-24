#include <iostream>
// #include <omp.h>
using namespace std;

void bubleSort(int arr[], int n)
{

    #pragma omp parallel for

    for (int i = 0; i < n - 1; i++)
    {
        bool swap = false;
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        if (!swap)
        {
            break;
        }

    }
}

int main()
{
    int arr[] = {3, 2, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}