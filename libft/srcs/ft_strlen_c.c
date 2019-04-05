/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:10:07 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/05 17:14:43 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strlen_c(char *str, char c)
{
	 char *cpy;

	 cpy = str;
	 while (*cpy)
	 {
		 if (*cpy == c)
			 return (cpy - str);
		 cpy++;
	 }
	 return (-1);
}
