int throw(char msg[])
{
  printf("Program Exception:\n%s", msg);
  return EXCEPTION;
}

double Re(double D, double rho, double u_mean, double mu)
{
  if (mu == 0)
    return throw("Division by zero exception. mu can't be 0.");

  return rho * u_mean * D / mu;
}

double f(double eps, double D, double Re)
{
  if (Re == 0 || D == 0)
    return throw("Division by zero exception.");

  return pow(-1.737 * log((0.269 * (eps / D)) - ((2.185 / Re) * log(0.269 * (eps / D)) + (14.5 / Re))), -2);
}

double error_func(double old_value, double new_value)
{
  if (old_value == 0)
    return throw("Division by zero exception.");

  // abs but for doubles
  return fabs((old_value - new_value) / old_value) * 100;
}