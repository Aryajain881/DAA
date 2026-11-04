// FIND THE TIME EXCEUTION FOR QUICK SORT


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    if (arr == NULL || n <= 0)
    {
        printf("Invalid input or memory allocation failed.");
        free(arr);
        return 1;
    }

    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;

    clock_t start = clock();

    quickSort(arr, 0, n - 1);

    clock_t end = clock();

    double execution_time =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");

    if (n <= 20)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        printf("Array too large to display.");
    }

    printf("\n\nExecution Time: %f seconds\n",
           execution_time);

    free(arr);
    return 0;
}
