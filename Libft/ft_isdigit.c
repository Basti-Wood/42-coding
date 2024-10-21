int ft_isdigit(char c){
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

/*


#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    c = 'q';
    printf("\nis digit: %d", ft_isdigit(c));

    return 0;
}
*/