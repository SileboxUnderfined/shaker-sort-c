#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int rand_max, length;

    printf("Enter max random integer: ");
    scanf("%d", &rand_max);
    printf("Enter array length: ");
    scanf("%d", &length);

    int* numbers = calloc(length, sizeof(int));

    for (int i = 0; i < length; i++) {
        numbers[i] = rand() % rand_max + 1;
    }

    printf("Initial array: ");
    print_array(numbers, length);

    clock_t start_time = clock();
    sort(numbers, length);
    clock_t end_time = clock();

    double result_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    print_array(numbers, length);

    printf("The array was sorted in %f ms", result_time);

    free(numbers);

    return 0;
}

void sort(int* numbers, int length) {
    unsigned char swapped = 0;
    int left = 0;
    int right = length - 1;
    
    while ((left < right) && (swapped == 0)) {
        swapped = 1;

        for (int i = left; i < right; i++) {
            if (numbers[i] > numbers[i+1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;

                swapped = 0;
            }
        }

        right--;

        if (swapped == 1) continue;
        swapped = 1;

        for (int i = right; i > left; i--) {
            if (numbers[i] < numbers[i-1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = temp;

                swapped = 0;
            }
        }

        left++;
    }
}

void print_array(int* numbers, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}