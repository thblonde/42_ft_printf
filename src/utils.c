#include "ft_printf.h"

int	countdigits(int n)
{
	int		count;
	long	num;

	count = 1;
	num = n;
	if (num < 0)
		num = -num;
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static int	check_base(const char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, const char *base)
{
	int		base_len;
	long	n;

	base_len = check_base(base);
	if (!base_len)
		return ;
	n = nbr;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	ft_putchar_fd(base[n % base_len], 1);
}
