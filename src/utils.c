#include "ft_printf.h"

int	countdigits(int n)
{
	int		count;
	long	num;

	count = 1;
	num = n;
	if (num < 0)
	{
		num = -num;
		count++;
	}
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

void	print_hexa(unsigned int nbr, const char *base, int *pcount)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr < (unsigned int)base_len)
	{
		ft_putchar_fd(base[nbr], 1);
		(*pcount)++;
	}
	else
	{
		print_hexa(nbr / (unsigned int)base_len, base, pcount);
		print_hexa(nbr % (unsigned int) base_len, base, pcount);
	}
}

void	print_pointer(unsigned long long nbr, char *base, int *pcount)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr < (unsigned long long)base_len)
	{
		ft_putchar_fd(base[nbr], 1);
		(*pcount)++;
	}
	else
	{
		print_pointer(nbr / (unsigned long long)base_len, base, pcount);
		print_pointer(nbr % (unsigned long long)base_len, base, pcount);
	}
}

void print_unsigned_int(unsigned int n, int fd, int *pcount)
{
    if (n == 0)
    {
        (*pcount)++;
        ft_putchar_fd('0', fd);
        return;
    }
    if (n < 10)
    {
        (*pcount)++;
        ft_putchar_fd((n + '0'), fd);
    }
    else
    {
        print_unsigned_int((n / 10), fd, pcount);
        print_unsigned_int((n % 10), fd, pcount);
    }
}

void	print_integer(int n, int fd, int *pcount)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		(*pcount) += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		(*pcount)++;
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar_fd((n + '0'), fd);
		(*pcount)++;
	}
	else
	{
		print_integer(n / 10, fd, pcount);
		ft_putchar_fd((n % 10) + '0', fd);
		(*pcount)++;
	}
}


