#include <stdio.h>

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int numbers[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    printf("Original array: ");
    print_array(numbers, size);

    int *s_ptr = numbers; // pointer at the srart of the array
    int *e_ptr = (numbers + size -1); // pointer at the end of the array

    for (int i = 0; i<(size/2);i++){
        // temp value to hold the value of the start pointer
        // cuz after that we will make the value of the start ptr the same as the end ptr
        int temp = *s_ptr; 
        *s_ptr = *e_ptr;
        *e_ptr = temp;
        s_ptr++;
        e_ptr--;
    }

    printf("Reversed array: ");
    print_array(numbers, size);

    return 0;
}