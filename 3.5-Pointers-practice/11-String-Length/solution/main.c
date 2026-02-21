#include <stdio.h>

int custom_strlen(char *str_ptr){
    int len = 0;
    while(*str_ptr!='\0'){
        str_ptr++;
        len++;
    }
    return (len+1); // return the len with counting \0 
}

int main(){

    char myString[] = "Hello Pointers!";
     int str_len = custom_strlen(myString);

    printf("Sting len: %d", str_len);

    return 0;
}