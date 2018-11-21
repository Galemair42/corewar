/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:30:52 by jabt              #+#    #+#             */
/*   Updated: 2018/03/28 16:51:18 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**						les includes libc
*/

# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
#include "libft.h"

/*
** 							color
*/

enum				e_color
{
	CHIFFRE = 1,
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	EOC
};

# define BUFF_SIZE 2048

/*
**			struct pour stocker le resultat de mon parsing de %
*/

typedef struct		s_formatint
{
	int			len;
	int			base;
	char		sign;
	intmax_t	*div;
}					t_formatint;

typedef struct		s_percent
{
	int				width;
	int				precision;
	char			flags[6];
	char			size[3];
	char			type;
	t_formatint		*intinfo;
}					t_percent;

/*
**					pointer's array on function
*/

typedef int			(*t_ptrstruct)(va_list *, t_percent *, char *, int *);

typedef struct		s_conv
{
	char			*str;
	t_ptrstruct		conv;
}					t_conv;

/*
**					le coeur
**					all the manage func are the same :
**					read the data according to the size
**					and return by calling the good put_*** function
**					wich will display correctly and return the length
**					of what had been print
*/

int					ft_printf(const char *format, ...);
int					ft_transformpercent(const char **format, va_list *ap,
		char *buffer, int *j);
char				*ft_transformcolor(const char **format);
int					ft_manage_signed_int(va_list *ap, t_percent *f,
		char *buffer, int *j);
int					ft_manage_unsigned_int(va_list *ap, t_percent *f,
		char *buffer, int *j);
int					ft_manage_wide_char(va_list *ap, t_percent *f,
		char *buffer, int *j);
int					ft_manage_addr(va_list *ap, t_percent *f,
		char *buffer, int *j);
int					ft_manage_string(va_list *ap, t_percent *f,
		char *buffer, int *j);
int					ft_manage_wide_string(va_list *ap, t_percent *f,
		char *buffer, int *j);
int					ft_manage_char(va_list *ap, t_percent *f,
		char *buffer, int *j);
void				ft_putbuf(char *buffer, int *j);
void				ft_putc_inbuf(char *buffer, char c, int *j);
void				ft_putstr_inbuf(char *buffer, char *str, int *j);
int					ft_putwidth_int(char *buffer, t_percent *f, int *j);
void				ft_putwidth(char *buffer, t_percent *f, int *j);
int					ft_putsignednb_inbuf(t_percent *f, char *buffer, int *j,
		intmax_t nb);
int					ft_putunsignednb_inbuf(t_percent *f, char *buffer, int *j,
		uintmax_t nb);
void				ft_putprecision_forint(char *buffer, t_percent *f, int *j);
void				ft_putunsignednb_inhexa_inbuf(t_percent *f, char *buffer,
		int *j, uintmax_t nb);
int					ft_putbinaire_inbuf(t_percent *f, char *buffer, int *j,
		uintmax_t nb);
int					ft_putsign(char *buffer, t_percent *f, int *j);
int					ft_putcarac(char c, t_percent *f, char *buffer, int *j);
int					ft_put_wide_carac(wchar_t *container, char *buffer, int *j);

/*
**				manip de ma struct format
*/

int					ft_freestruct(t_percent *f);
t_percent			*ft_initstruct(void);
void				ft_init_int_struct(t_percent *f);
void				ft_fillstruct(const char **format, va_list *ap,
		t_percent **f);
void				ft_putstruct(t_percent *f);
void				ft_addflag(t_percent *f, char c);
void				ft_removeflag(t_percent *f, char c);

/*
**			parsing of flags / width / precision / size / type and colors
**			check width / pre / flag / size,
**			careful the pointeur format is incremente here
*/

void				ft_checkflag(t_percent *f, char *sign, const char **c);
void				ft_checkwidth(t_percent *f, va_list *ap,
		const char **format);
void				ft_checkprecision(t_percent *f, va_list *ap,
		const char **format);
void				ft_checksize(t_percent *f, const char **format,
		char *sign);
int					*ft_givecolor(const char **format);
int					*ft_findrightcolor(char *color);

/*
**			and here all the functions which permits to speak by real
**			pre and width
**			for instance i want to print 42 with a width of 3 so by calling
**			those function i will have 1 and if if get a negative width 0
*/

void				ft_add_widthandpre_toint(t_percent *f);
int					ft_add_widthandpre_towchar(t_percent *f, wchar_t *str,
		int len);
int					ft_turninto_fourbytes_precision(t_percent *f, wchar_t *str,
		int len);
void				ft_add_unsigned_len(t_percent *f, uintmax_t *nb,
		uintmax_t *div);

#endif
