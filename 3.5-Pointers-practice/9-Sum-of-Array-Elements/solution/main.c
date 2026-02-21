#include <stdio.h>

int sum_array(int *arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += *(arr+i);
    }
    return sum;
}

int main(){

    int numbers[] = {10, 5, 8, 2, 15};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    int sum = sum_array(numbers,size);
    printf("The sum of array elements is: %d\n",sum );


    return 0;
}