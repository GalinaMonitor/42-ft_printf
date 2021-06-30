#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <inttypes.h>
# include "libft/libft.h"

# define FLAG_FLG_0		0b000000000000001
# define FLAG_FLG_MIN	0b000000000000010
# define FLAG_SHR_ARG	0b000000000000100
# define FLAG_SHR_DIG	0b000000000001000
# define FLAG_PRS_ARG	0b000000000010000
# define FLAG_PRS_DIG	0b000000000100000
# define FLAG_TYP_D		0b000000001000000
# define FLAG_TYP_I		0b000000010000000
# define FLAG_TYP_U		0b000000100000000
# define FLAG_TYP_C		0b000001000000000
# define FLAG_TYP_S		0b000010000000000
# define FLAG_TYP_P		0b000100000000000
# define FLAG_TYP_X		0b001000000000000
# define FLAG_TYP_XB	0b010000000000000
# define FLAG_TYP_PR	0b100000000000000

typedef struct	flags {
	int flags;
	int	shirina;
	int	precision;
	int arg_type;
	int count_print;

}	flags;

char		*ft_shirina(char *str, flags *flags);
char		*ft_precision(char *str, flags *flags);
char		*ft_type_parse(va_list arg, flags *flags);
const char	*ft_parser_GOD(const char *input, va_list arg, flags *flags);
int			ft_processor(va_list arg, flags *flags);
int			ft_parse(va_list arg, const char *input);
int			ft_printf(const char *input, ...);
char		*ft_itoa_base16(unsigned long nbr, flags *flags);
char		*ft_itoa_unsigned(char *word, int ind, long n, flags *flags);
static int	ft_intlen(long n);
unsigned long long	*ft_long_digits(unsigned long long nbr);
unsigned long long	*ft_long_digits_sum(unsigned long long *digits, unsigned long long *digits2);
unsigned long long	*ft_long_digits_division(unsigned long long *digits, unsigned long long num);
unsigned long long	*ft_long_digits_min(unsigned long long *digits, long long *digits2);
unsigned long long	*ft_long_digits_multiply(unsigned long long *digits, unsigned long long *digits2);
void	ft_long_digits_printf(unsigned long long *digits);

#endif
