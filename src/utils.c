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
