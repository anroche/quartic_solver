/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anroche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:51:44 by anroche           #+#    #+#             */
/*   Updated: 2018/03/24 16:51:52 by anroche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>

double ft_max(double u, double v);
double *ft_solve_3(double a, double b, double c, double d);
double	*ft_solve_4(double t[5]);

int main(int av, char **ac)
{
	if (av == 6)
	{
		int i;
		double  var[5];
		
		double	*ret;

		
		var[0] = atof(ac[1]);
		var[1] = atof(ac[2]);
		var[2] = atof(ac[3]);
		var[3] = atof(ac[4]);
		var[4] = atof(ac[5]);


	
		ret = ft_solve_4(var);
		i = -1;
		ft_putstr("the real solutions of the equation:\n");
		while (++i < 4)
			printf("%d/ %f\n",i + 1,ret[i]);
	}
	else
	{
		ft_putstr("\nInvalid equation\n\n");
		ft_putstr("The equation is of the form:\n");
		ft_putstr("Ax4 + Bx3 + Cx2 + Dx + E = 0\n");
		ft_putstr("You should send the value of A, B, C, D, E.\n");


	}


	return (0);
}