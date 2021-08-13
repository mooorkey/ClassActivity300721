#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char* to_hex(int value){
    char HEX_DIGITS[] = "0123456789abcdef";
    char* s = malloc(sizeof(char)*100);

    if(value < 0)
    {
        int64_t i = 1;
        value += (i << 32);
    }

    int l = 0;
    
    while(1)
    {
        char d[2] = {HEX_DIGITS[(value & 0xf)], '\0'};  //value = 3(dec)   = 0011(bin)
        char* r = strdup(s);                            //value = 0xf(hex) = 1111(bin) 
        strcpy(s, d);
        strcat(s, r);
        //printf("d(while) = %s\n", d);
        //printf("s(while) = %s\n", s);
        l++;
        value >>= 4;
        if(value == 0 || l == 8) break;
    }
    char* r = strdup(s);
    char x[] = "0x";
    strcat(x, r);
    free(s);
    strcat(s, x);
    /*printf("r = %s\n", r);
    printf("x = %s\n", x);
    printf("s = %s\n", s);*/
    return s;
}

int main(){
    char* a = to_hex(88888);
    printf("%s\n", a);
    return 0;
}
