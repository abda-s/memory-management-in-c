#include <stdio.h>

void custom_strcpy(char *src, char *dest){
    while(*src!='\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main(){

    char source[] = "Pointer Mastery";
    char destination[50];
     
    custom_strcpy(source, destination);

    printf("Source: %s\n", source);
    printf("Dest: %s\n", destination);

    return 0;
}