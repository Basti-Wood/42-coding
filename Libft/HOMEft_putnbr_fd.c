#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
        return ;
	}
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
    }
    if (n < 10)
    {
        c = n + '0';
        ft_putchar_fd(c, fd);
    }
    else
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }

}