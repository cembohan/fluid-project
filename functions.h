/*
 * function.h
 *
 *  Created on: 23 Nis 2020
 *      Author: Cem
 */
#define PI 3.1416

#define EXCEPTION -1

#ifndef FUNCTION_H_
#define FUNCTION_H_

void throw(char msg[])
{
  printf("Program Exception:\n%s", msg);
  exit(EXCEPTION);
}
double umean(double Q, double D)
{
	if (D == 0)
		throw("Division by zero exception.");

	return 4 * Q / PI / pow(D,2);
}
double umean2(double D, double fF, double rho, double L,double deltaP,double g, double deltaz){
	return pow(D/2/fF/rho/L*(deltaP-(rho*g*deltaz)),0.5);
}

double RE(double D, double rho, double u_mean, double mu)
{
  if (mu == 0)
    throw("Division by zero exception. mu can't be 0.");

  return rho * u_mean * D / mu;
}

double f(double eps, double D, double Re)
{
  if (Re == 0 || D == 0)
    throw("Division by zero exception.");

  return pow(-1.737 * log((0.269 * (eps / D)) - (2.185 / Re) * (log(0.269 * (eps / D) + (14.5 / Re)))), -2);
}

double error_func(double old_value, double new_value)
{
  if (old_value == 0)
    throw("Division by zero exception.");

  // abs but for doubles
  return fabs((old_value - new_value) / old_value) * 100;
}
double pdrop (double fF, double rho, double u_mean, double L, double D, double g, double deltaz)
{
	return  ((2 * fF * rho * u_mean * u_mean * L / D ) + rho * g * deltaz)/144/32.174;
}

#endif /* FUNCTION_H_ */
