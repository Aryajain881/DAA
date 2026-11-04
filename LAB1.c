//write and display all the elemnet of an array
#include <stdio.h>

int main() {
    int a[5] = {10, 20, 30, 40, 50};

    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

//find largest element in an array
#include <stdio.h>

int main() {
    int a[5] = {10, 25, 7, 40, 15};
    int max = a[0];

    for(int i = 1; i < 5; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }

    printf("Largest element = %d", max);

    return 0;
}

// find the sum of all number in an arrary and find it average 
#include <stdio.h>

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int sum = 0;
    float average;

    for(int i = 0; i < 5; i++) {
        sum = sum + a[i];
    }

    average = sum / 5.0;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f", average);

    return 0;
}


// reverse the array
#include <stdio.h>

int main() {
    int a[5] = {10, 20, 30, 40, 50};

    for(int i = 4; i >= 0; i--) {
        printf("%d ", a[i]);
    }

    return 0;
}