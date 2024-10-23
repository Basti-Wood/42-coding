#include "libft.h"
static size_t  sft_strlen(const char *str){
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

size_t  ft_strlcat(char *dst, const char *src, size_t size){
    size_t i;
    size_t len;

    i = 0;
    len = 0;

    while(dst[len] && len < size){
        len++;
    }
    i = len;
    while(src[len - i] && len + 1 < size){
        dst[len] = src[len - i];
        len++;
    }
    if (i < size){
        dst[len] = '\0';
    }
    return (i + sft_strlen(src));

}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Hello, ";  // Destination string
    const char *src = "World!";
    size_t maxSize = sizeof(dest) - 1; // Calculate space available for concatenation

    // Concatenating src to dest with size limit
    ft_strlcat(dest, src, maxSize);

    // Output the result
    printf("Concatenated String: %s\n", dest);

    return 0;
}
