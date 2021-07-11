#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

# define FLAG_FLG_0		0b000000000000000000001
# define FLAG_FLG_MIN	0b000000000000000000010
# define FLAG_FLG_PLUS	0b000000000000000000100
# define FLAG_FLG_SHARP	0b000000000000000001000
# define FLAG_FLG_SPC	0b000000000000000010000
# define FLAG_SHR_ARG	0b000000000000000100000
# define FLAG_SHR_DIG	0b000000000000001000000
# define FLAG_PRS_ARG	0b000000000000010000000
# define FLAG_PRS_DIG	0b000000000000100000000
# define FLAG_PRS		0b000000000000110000000
# define FLAG_TYP_D		0b000000000001000000000
# define FLAG_TYP_I		0b000000000010000000000
# define FLAG_TYP_U		0b000000000100000000000
# define FLAG_TYP_C		0b000000001000000000000
# define FLAG_TYP_S		0b000000010000000000000
# define FLAG_TYP_P		0b000000100000000000000
# define FLAG_TYP_X		0b000001000000000000000
# define FLAG_TYP_F		0b000010000000000000000
# define FLAG_TYP_FMIN	0b000100000000000000000
# define FLAG_TYP_XB	0b001000000000000000000
# define FLAG_TYP_PR	0b010000000000000000000
# define FLAG_C_NULL	0b100000000000000000000

typedef struct s_flags
{
	int	flags;
	int	shirina;
	int	precision;
	int	arg_type;
	int	count_print;

}	t_flags;

typedef union s_fdigit
{
	long double digit;
	struct
	{
		uint64_t mantissa: 64;
		uint16_t exponent: 15;
		uint8_t minus: 1;
	};
}	s_fdigit;

typedef struct	s_float_length
{
	int		int_part;
	int		result_fract_part;
	int		result_length;
} s_float_length;

int					ft_printf(const char *input, ...);
int					ft_parse(va_list arg, const char *input);
int					ft_printtrash_and_parse(va_list arg, t_flags *flags, const char *input);
int					ft_check_type_and_parse(const char *input, va_list arg, t_flags *flags);
int					ft_parser_god(const char *input, va_list arg, t_flags *flags);
char				*ft_type_parse(va_list arg, t_flags *flags);
int					ft_processor(va_list arg, t_flags *flags);
void				ft_print_end_of_string(char	*str, t_flags *flags);
int					ft_parse_flags(const char *input, int ind, t_flags *flags);
int					ft_parse_shirina(const char *input, int ind, t_flags *flags, va_list arg);
void				ft_shirina_sec(int spaces, char *result, char *str, t_flags *flags);
int					ft_parse_precision(const char *input, int ind, t_flags *flags, va_list arg);
void				ft_parse_type(char input, t_flags *flags);
char				*ft_parsing_d(va_list arg);
char				*ft_parsing_u(va_list arg);
char				*ft_parsing_x(va_list arg, t_flags *flags);
char				*ft_parsing_p(va_list arg, t_flags *flags);
char				*ft_parsing_s(va_list arg);
char				*ft_parsing_c(va_list arg, t_flags *flags);
char				*ft_parsing_pr(t_flags *flags);
char				*ft_shirina(char *str, t_flags *flags);
char				*ft_precision(char *input, t_flags *flags);
char				*ft_precision_digits(char *input, t_flags *flags);
char				*ft_precision_str(char *input, t_flags *flags);
char				*ft_itoa_base(unsigned long long nbr, short base, t_flags *flags);
int					ft_intlen_base(unsigned long long n, short base);
char				*ft_precision_digits(char *str, t_flags *flags);
char				*ft_precision_str(char *str, t_flags *flags);

char				*ft_parsing_float(va_list arg, t_flags *flags);
int					ft_parsing_float_fract(int ind, long long unsigned **fract, s_fdigit *fdigit);
int					ft_parsing_float_int(int power, long long unsigned **nbr, t_flags *flags, s_fdigit *fdigit);
char				*ft_float_check_nan(s_fdigit *fdigit, t_flags *flags, char *str);


unsigned long long	*ft_long_digits(unsigned long long nbr, unsigned long long base);
unsigned long long	*ft_long_digits_sum(unsigned long long *digits, unsigned long long *digits2, unsigned long long base);
unsigned long long	*ft_long_digits_division(unsigned long long *digits, unsigned long long num, unsigned long long base);
unsigned long long	*ft_long_digits_min(unsigned long long *digits, long long *digits2, unsigned long long base);
unsigned long long	*ft_long_digits_multiply(unsigned long long *digits, unsigned long long *digits2, unsigned long long base);
void				ft_long_digits_printf(unsigned long long *digits, unsigned long long base, int count);
unsigned long long	*ft_long_digits_power(unsigned long long *digits, int power, unsigned long long base);
char				*ft_long_digits_to_str(unsigned long long **digits, unsigned long long base, int count, t_flags *flags);

char				*ft_precision_float(char *input, t_flags *flags);
int					ft_rounding_up_five_plus(s_float_length *float_length, char *input, char **result);
void				ft_rounding_up_zero_prec(s_float_length *float_length, char *input, char **result);
int					ft_rounding_up(int count, int ind, char *input);
void				ft_fill_struct_float(char *input, s_float_length *float_length, t_flags *flags);

char				*ft_parsing_float(va_list arg, t_flags *flags);

int					ft_check_if_type(const char *input);
void				ft_null_struct(t_flags *flags);
int					ft_cmp_memory_length(char *input, char **result, int len_input, t_flags *flags);
#endif
