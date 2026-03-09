#include <stdio.h>
#include <string.h>

void check_addr(char* ptr, char arr[]){
    printf("ptr:\t%s\n", ptr);
    printf("arr:\t%s\n", arr);

    printf("sizeof:\t%ld\n", sizeof(arr));
}

int main()
{
    char str[] = "hello world!";
    printf("sizeof:\t%ld\n", sizeof(str));
    check_addr(str,str);
    return 0;
}