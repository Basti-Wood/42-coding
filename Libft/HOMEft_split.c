#include "libft.h"

// Helper function to count the number of substrings
static size_t count_words(const char *s, char c) {
    size_t count = 0;
    int in_word = 0;

    while (*s) {
        if (*s != c && !in_word) {
            in_word = 1;
            count++;
        } else if (*s == c) {
            in_word = 0;
        }
        s++;
    }
    return count;
}

// Helper function to duplicate a substring using ft_memcpy
static char *duplicate_str(const char *start, size_t len) {
    char *str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    ft_memcpy(str, start, len);
    str[len] = '\0';
    return str;
}

char **ft_split(char const *s, char c) {
    if (!s)
        return NULL;

    size_t words = count_words(s, c);
    char **result = (char **)malloc(sizeof(char *) * (words + 1));
    if (!result)
        return NULL;

    size_t i = 0;
    while (*s) {
        if (*s != c) {
            const char *start = s;
            size_t len = 0;
            while (*s && *s != c) {
                len++;
                s++;
            }
            result[i++] = duplicate_str(start, len);
            if (!result[i - 1]) {  // Check for allocation failure
                while (i > 0) {
                    free(result[--i]);
                }
                free(result);
                return NULL;
            }
        } else {
            s++;
        }
    }
    result[i] = NULL;
    return result;
}
