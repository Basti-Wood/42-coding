int ft_isascii(int c){
    if (c >= 0 && c <= 127){
        return 1;
    }
    return 0;
}
/*
#include <stdio.h>
#include <ctype.h>

int main() {
    unsigned char ch = 'A';  // A non-ASCII character (n-tilde)

    if (ft_isascii(ch)) {
        printf("%c is an ASCII character.\n", ch);
    } else {
        printf("%c is NOT an ASCII character.\n", ch);
    }

    return 0;}
*/