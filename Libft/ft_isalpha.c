
//int isalpha(int argument);

int ft_isalpha(int argument){
    if ((argument >= 'A' || argument <= 'Z') && (argument >= 'a' || argument <= 'z')) {
        return 1;
    }
    return 0;
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;
    c = 'q';
    printf("\nResult when uppercase alphabet is passed: %d", isalpha(c));

    c = 'Q';
    printf("\nResult when lowercase alphabet is passed: %d", isalpha(c));

    c = 1;
    printf("\nResult when non-alphabetic character is passed: %d", isalpha(c));

    char ft;
    ft = 'q';
    printf("\nResult when uppercase alphabet is passed: %d", ft_isalpha(ft));

    ft = 'Q';
    printf("\nResult when lowercase alphabet is passed: %d", ft_isalpha(ft));

    ft = 1;
    printf("\nResult when non-alphabetic character is passed: %d", ft_isalpha(ft));

    return 0;
}*/