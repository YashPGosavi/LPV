#include <iostream>
// #include <omp.h>
using namespace std;

int main()
{
    int arr[] = {5, 2, 8, 1, 6, 9, 3, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // sum
    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "sum: " << sum << endl;

    // min
    int min = arr[0];
#pragma omp parallel for reduction(min : min)
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "min: " << min << endl;

    // max
    int max = arr[0];
#pragma omp parallel for reduction(max : max)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "max: " << max << endl;

    // avg
    int avg = sum / n;
    cout << "avg: " << avg << endl;
}