int ft_isprint(int c){
    if (c >= 32 && c <= 126){
        return 1;
    }
    return 0;
}

/*


#include <stdio.h>
#include <ctype.h>

int main() {
    char ch1 = 'A';   // Printable character
    char ch2 = '\n';  // Non-printable character

    if (ft_isprint(ch1)) {
        printf("'%c' is a printable character.\n", ch1);
    } else {
        printf("'%c' is NOT a printable character.\n", ch1);
    }

    if (ft_isprint(ch2)) {
        printf("'%c' is a printable character.\n", ch2);
    } else {
        printf("'%c' is NOT a printable character.\n", ch2);
    }

    return 0;
}
*/