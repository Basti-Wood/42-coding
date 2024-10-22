#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (n--)
		str[i++] = 0;
}
/*

#include <stdio.h>
#include <strings.h>  // for bzero

int main() {
    // Define a character array (buffer) with some initial data
    char buffer[10] = "hello";

    // Print the buffer before bzero
    printf("Buffer before bzero: '%s'\n", buffer);

    // Use bzero to zero out the memory of the buffer
    bzero(buffer, sizeof(buffer));

    // Print the buffer after bzero
    printf("Buffer after bzero: '%s'\n", buffer);

    return 0;
}
*/