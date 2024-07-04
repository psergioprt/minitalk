/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:32:08 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/28 11:22:00 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "../util_funcs/Libft/libft.h"
# include "../util_funcs/ft_printf/ft_printf.h"

void	ft_perror_x(const char *s, const char *error_msg, int exit_code);
void	output_error_usage(const char *program_name);

#endif
