#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <libc.h>
# include "../42_libft/libft.h"

int ft_printf(const char *s, ...);

/* format */
void    string(va_list arg, int *pcount);
void    pointer(va_list arg, int *pcount);
void    integer(va_list arg, int *pcount);
void    unsigned_int(va_list arg, int *pcount);
void    hexadecimal(va_list arg, int *pcount, char c);

/* utils */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(int nbr, const char *base);
int	    countdigits(int n);
void	ft_putnbr_fd(int n, int fd);

#endif
