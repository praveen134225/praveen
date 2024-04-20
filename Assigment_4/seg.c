#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

int main() {
    int *ptr1 = malloc(sizeof(int) * ARRAY_SIZE);
    if (ptr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Accessing elements of the array
    for (int i = 0; i <= ARRAY_SIZE; i++) {
        ptr1[i] = i;
    }

    // Trying to access an element beyond the allocated memory
    int *ptr2 = NULL;
    printf("Accessing ptr2: %d\n", *ptr2); // This will cause a segmentation fault

    // Freeing memory
    free(ptr1);
    ptr1 = NULL;

    // Accessing a freed memory
    printf("Accessing freed memory: %d\n", ptr1[0]); // This will also cause a segmentation fault

    return 0;
}

