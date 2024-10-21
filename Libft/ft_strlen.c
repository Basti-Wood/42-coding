int ft_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
/*



#include <stdio.h>
#include <string.h>

int main() {
    // Example string
    char str1[] = "Hello, World!";
    char str2[] = "";  // Empty string

    // Using strlen to calculate the length of the strings
    size_t len1 = ft_strlen(str1);  // Should return 13 (excluding the null character)
    size_t len2 = ft_strlen(str2);  // Should return 0 (empty string)

    // Displaying the lengths
    printf("Length of '%s' is: %zu\n", str1, len1);
    printf("Length of an empty string is: %zu\n", len2);

    return 0;
}
*/