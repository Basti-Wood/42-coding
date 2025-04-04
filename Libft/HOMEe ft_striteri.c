#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int i;

    i = 0;
	if (s && f)
		while (s[i])
		{
			f(i, &s[i]);
			i += 1;
		}
}