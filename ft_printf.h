#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <inttypes.h>
# include <float.h>
# include "libft/libft.h"

# define FLAG_FLG_0		0b0000000000000001
# define FLAG_FLG_MIN	0b0000000000000010
# define FLAG_SHR_ARG	0b0000000000000100
# define FLAG_SHR_DIG	0b0000000000001000
# define FLAG_PRS_ARG	0b0000000000010000
# define FLAG_PRS_DIG	0b0000000000100000
# define FLAG_TYP_D		0b0000000001000000
# define FLAG_TYP_I		0b0000000010000000
# define FLAG_TYP_U		0b0000000100000000
# define FLAG_TYP_C		0b0000001000000000
# define FLAG_TYP_S		0b0000010000000000
# define FLAG_TYP_P		0b0000100000000000
# define FLAG_TYP_X		0b0001000000000000
# define FLAG_TYP_XB	0b0010000000000000
# define FLAG_TYP_F		0b0100000000000000
# define FLAG_TYP_FMIN	0b1000000000000000

typedef struct	s_flags {
	int flags;
	int	shirina;
	int	precision;
	int arg_type;
	int count_print;
	int test1;
	int test2;

}	s_flags;

typedef union fdigit
{
		long double digit;
		struct
		{
			uint64_t mantissa: 64;
			uint16_t exponent: 15;
			uint8_t minus: 1;
		};
}	fdigit;

char		*ft_shirina(char *str, s_flags *flags);
char		*ft_precision(char *str, s_flags *flags);
char		*ft_type_parse(va_list arg, s_flags *flags);
int			ft_parser_GOD(const char *input, va_list arg, s_flags *flags);
int			ft_processor(va_list arg,s_flags *flags);
int			ft_parse(va_list arg, const char *input);
int			ft_printf(const char *input, ...);
char		*ft_itoa_base(unsigned long long nbr, short base,s_flags *flags);
char		*ft_itoa_unsigned(char *word, int ind, long n, s_flags *flags);
int	ft_intlen_base(long n, short base);
unsigned long long	*ft_long_digits(unsigned long long nbr, unsigned long long base);
unsigned long long	*ft_long_digits_sum(unsigned long long *digits, unsigned long long *digits2, unsigned long long base);
unsigned long long	*ft_long_digits_division(unsigned long long *digits, unsigned long long num, unsigned long long base);
unsigned long long	*ft_long_digits_min(unsigned long long *digits, long long *digits2, unsigned long long base);
unsigned long long	*ft_long_digits_multiply(unsigned long long *digits, unsigned long long *digits2, unsigned long long base);
void	ft_long_digits_printf(unsigned long long *digits, unsigned long long base, int count);
unsigned long long	*ft_long_digits_power(unsigned long long *digits, int power, unsigned long long base);
char	*ft_long_digits_to_str(unsigned long long *digits, unsigned long long base, int count, s_flags *flags);
char	*ft_parsing_float(long double digit, s_flags *flags);
char	*ft_precision_digits(char *str, s_flags *flags);
char	*ft_precision_str(char *str, s_flags *flags);

char	*ft_precision_float(char *str, s_flags *flags);

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif
