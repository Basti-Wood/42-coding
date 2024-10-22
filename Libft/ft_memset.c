#include "libft.h"

void *ft_memset(void *b, int c, size_t len) {
    unsigned char *p = (unsigned char *)b;
    while (len > 0) {
        *p = (unsigned char)c;
        p++;
        len--;
    }
    return b;
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char buffer[10];
    ft_memset(buffer, 'A', sizeof(buffer) - 1);  // Leave space for null terminator
    buffer[9] = '\0';  // Null-terminate the string
    
    printf("%s\n", buffer);  // Output: AAAAAAAAA
    return 0;
}
*/