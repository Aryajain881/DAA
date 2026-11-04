// //iterative apporach 

// #include <stdio.h>

// int binarySearch(int arr[], int size, int key) {
//     int low = 0, high = size - 1;

//     while (low <= high) {
//         int mid = (low + high)/ 2;

//         if (arr[mid] == key)
//             return mid;  

//         if (arr[mid] < key)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }

//     return -1;  
// }

// int main() {
//     int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int key;

//     printf("Enter the element to search: ");
//     scanf("%d", &key);

//     int result = binarySearch(arr, size, key);

//     if (result != -1)
//         printf("Element found at index %d\n", result);
//     else
//         printf("Element not found\n");

//     return 0;
// }

// recursive apporch
// #include <stdio.h>

// int binarySearch(int arr[], int low, int high, int key)
// {
//     if (low > high)
//         return -1;

//     int mid = (low + high) / 2;

//     if (arr[mid] == key)
//         return mid;

//     if (key < arr[mid])
//         return binarySearch(arr, low, mid - 1, key);
//     else
//         return binarySearch(arr, mid + 1, high, key);
// }

// int main()
// {
//     int arr[] = {10, 20, 30, 40, 50};
//     int n = 5;
//     int key;

//     printf("Enter number to search: ");
//     scanf("%d", &key);

//     int result = binarySearch(arr, 0, n - 1, key);

//     if (result == -1)
//         printf("Number not found");
//     else
//         printf("Number found at index %d", result);

//     return 0;
// }


//FIND THE EXECUTION TIME OF BINARY SEARCH ALGORITHM
#include<stdio.h>
#include<time.h>

void binary_search(int arr[],int l,int r, int x){
    if (l>r){
        printf("elem not present\n");
    }
    else{
        int mid=(l+r)/2;
        if(arr[mid]==x){
            printf("elem present at index %d\n",mid);
        }
        else if(arr[mid]>x){
            binary_search(arr,l,mid-1,x);
        }
        else{
            binary_search(arr,mid+1,r,x);
        }
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start,end;
    double cpu_time_used;
    
    start=clock();
    binary_search(arr,0,n-1,6);
    end=clock();
    
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("%f seconds\n",cpu_time_used);
    
    return 0;
}