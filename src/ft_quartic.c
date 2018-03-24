/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quartic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anroche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:51:09 by anroche           #+#    #+#             */
/*   Updated: 2018/03/24 16:51:13 by anroche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

double ft_max(double u, double v);
double *ft_solve_3(double a, double b, double c, double d);

double	*ft_solve_4(double t[5])
    {

    	double *result;
    	double *roots;

    	double a0;
    	double a1;
		double a2;
		double  a3;
		
		double	b0;
		double	b1;
		double	b2;
    
		double	y;
 		double R;

 		double D;
 		double E;

         a0= t[0] / t[4];
         a1 = t[1] / t[4];
         a2 = t[2] / t[4];
         a3 = t[3] / t[4];
        result = malloc(sizeof(double) * 4.0);

    
        b0 = 4.0 * a2 * a0 - a1 * a1 - a3 * a3 * a0;
        b1 = a1 * a3 - 4.0 * a0;
        b2 = -a2;
     
	    roots = ft_solve_3(b0, b1, b2, 1.0);
   
        y = ft_max(roots[0], ft_max(roots[1], roots[2]));
		R = 0.25 * a3 * a3 - a2 + y;
        
        if ( R < 0.0 )
            return (0);
        R = sqrt( R );
        
        if ( R == 0.0 )
        {
            D = sqrt( 0.75 * a3 * a3 - 2.0 * a2 + 2.0 * sqrt( y * y - 4.0 * a0 ) );
            E = sqrt( 0.75 * a3 * a3 - 2.0 * a2 - 2.0 * sqrt( y * y - 4.0 * a0 ) );
        }
        else
        {
            double Rsquare = R * R;
            double Rrec = 1.0 / R;
            D = sqrt( 0.75 * a3 * a3 - Rsquare - 2.0 * a2 + 0.25 * Rrec * (4.0 * a3 * a2 - 8.0 * a1 - a3 * a3 * a3) );
            E = sqrt( 0.75 * a3 * a3 - Rsquare - 2.0 * a2 - 0.25 * Rrec * (4.0 * a3 * a2 - 8.0 * a1 - a3 * a3 * a3) );
        }

        result[0] = -0.25 * a3 + 0.5 * R + 0.5 * D;
        result[1] = -0.25 * a3 + 0.5 * R - 0.5 * D;
        result[2] =  -0.25 * a3 - 0.5 * R + 0.5 * E;
        result[3] = -0.25 * a3 - 0.5 * R - 0.5 * E;

        return (result);
    }