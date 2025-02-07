#include "ft_printf.h"

void    string(va_list arg, int *pcount)
{
    char    *tmp;

    tmp = va_arg(arg, char *);
    if (!tmp)
        tmp = "(null)";
    ft_putstr_fd(tmp, 1);
    *pcount += ft_strlen(tmp);
}

void    pointer(va_list arg, int *pcount)
{
    unsigned long long  p;

    p = va_arg(arg, unsigned long long);
    ft_putstr_fd("0x", 1);
    print_pointer(p, "0123456789abcdef", pcount);
    *pcount += 2;
}

void    integer(va_list arg, int *pcount)
{
    int i;

    i = va_arg(arg, int);
    print_integer(i, 1, pcount);
}

void    unsigned_int(va_list arg, int *pcount)
{
    unsigned int    u;

    u = va_arg(arg, unsigned int);
    print_unsigned_int(u, 1, pcount);
}

void    hexadecimal(va_list arg, int *pcount, char c)
{
    unsigned int   x;

    x = va_arg(arg, unsigned int);
    if (c == 'x')
        print_hexa(x, "0123456789abcdef", pcount);
    else
        print_hexa(x, "0123456789ABCDEF", pcount);
}
