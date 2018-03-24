/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anroche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:51:32 by anroche           #+#    #+#             */
/*   Updated: 2018/03/24 16:51:35 by anroche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

double *ft_solve_3(double a, double b, double c, double d)
    {
      
       double a1 = c / d;
       double a2 = b / d;
       double a3 = a / d;
	
       double *Result;
       Result = malloc(sizeof(double) * 3.0);

        double Q = (a1 * a1 - 3.0 * a2) / 9.0;
       	double R = (2.0 * a1 * a1 * a1 - 9.0 * a1 * a2 + 27.0 * a3) / 54.0;
        double Qcubed = Q * Q * Q;
        d = Qcubed - R * R;
		
        if ( d >= 0.0001 )
        {	// Three real roots
            if ( Q < 0.0 )
            {
            	Result[0] = 0;
            	Result[1] = 0;
            	Result[2] = 0;
	                return (Result);
            }
	
            double theta = acos(R / sqrt(Qcubed));
            double sqrtQ = sqrt(Q);
         
            Result[0] = -2.0 * sqrtQ * cos(theta / 3.0) - a1 / 3.0;
            Result[1] = -2.0 * sqrtQ * cos((theta + 2.0 * M_PI) / 3.0 ) - a1 / 3.0;
            Result[2] = -2.0 * sqrtQ * cos((theta + 4.0 * M_PI) / 3.0 ) - a1 / 3.0;

        }

        else
        {	// One real root
            double e = pow(sqrt(-d) + fabs(R), 1.0/ 3.0);
            if ( R > 0 )
                e = -e;
	
            Result[0] = Result[1] = Result[2] = (e + Q / e) - a1 / 3.0;
        }

        return (Result);
    }