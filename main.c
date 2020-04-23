// Include the constants first so that the rest of the files can access them
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "constants.h"
#include "functions.h"

int main(int argc, char const *argv[])
{
  printf("%f\n", Re(0.1, 2.2, 3, 1));
  printf("%f\n", f(0.001, 25, 0.66));
  printf("%f\n", error_func(3, 4));

  return 0;
}
