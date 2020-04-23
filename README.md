# fluid-project

General purpose of the program is to solvesimple piping problems.Write a general purpose Cor Matlabcodethat will accommodate the solution for as wide a variety  as possible of simple piping problems. Make sure that it can handle Case 1-2-3-type problems, and it gives output for these three cases.

variable names are given

In order to simplify the code and avoid unnecessary repetition of calculations, your program should contain the following functions:1.A function that calculates Reynolds number:Re(double D, double rho, double u_mean, double mu)2.A function that calculates friction factor:f(double eps, double D, double Re)3.An error function to check the convergence for Re in CASE 2-3:error_func(double old_value, double new_value)

In the beginning of the code, you can define constants using #defineif you decide to use C. Ex: #define PI 3.1416Please set the tolerance value tolto 0.001 for the convergence. The error checking should be performed according to the following formula:
error%= abs((old value-new value)/old value)*100

For CASE-2, initial guess for Re can beset to100,000 and for CASE-3, initial guess for D can be set to 10.Your program should be user friendly and clear. Add required commentsto the source code to make it understandable.

Input/output:-The program must request the user to enter the case type (1, 2 or 3) and unit system e.g. SI(m/kg/s)or FPS (ft/lbm/s).-As input, the program must request thediameter (D), flow rate (Q) or pressure drop (ΔP) depending on the case typewith specified unitsin Table 1.Example: Please specify the pipe diameter D (m):OrPlease specify the flow rate Q(ft3/s):-Outputs of the program should be clearly presented to the userwith appropriate units.-Other values you need could be taken as constants or you can request from user.

