/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:45:19 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/28 11:57:52 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

unsigned int		ft_putnbru_fd(unsigned int n, int fd);
unsigned int		ft_putnbr16_fd(unsigned int n, int fd, char *base);
unsigned long		ft_putptr_pf(unsigned long n, int fd, char *base);
int					ft_printf(const char *str, ...);
int					ft_strlen(const char *str);
int					l_i_s(long n, int b);
int					l_i_u(unsigned int n, int b);
int					l_i_up(unsigned long n, int b);
int					ft_putnbr_pf(int n, int fd);

#endif
