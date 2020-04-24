/*
 * asd.c
 *
 *  Created on: 23 Nis 2020
 *      Author: Cem
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"


int main() {
	setbuf(stdout, NULL);

	int a;
	int b;
	int c;
	double L;
	double eps;
	double D;
	double rho;
	double mu;
	double deltaz;;
	double g_SI = 9.81;
	double g_FPS = 32.17;
	double pV;
	double Q;
	double u_mean;
	double deltaP;
	double Re;
	double fF;
	double tol = 0.001;
	double P;
	/*
int main(int argc, char const *argv[])
{
 	  printf("%f\n", Re(0.1, 2.2, 3, 1));
  	  printf("%f\n", f(0.001, 25, 0.66));
  	  printf("%f\n", error_func(3, 4));
  	  printf("%f\n", PI);
  */

	printf("Please type which case you want to select. \nYour options are 1,2 or 3.\n");
	//fflush( stdout );
	scanf("%d", &a);

	if (a == 1 || a == 2 || a == 3) {
		printf("Which unit system do you want to use? Type 1 for SI, 2 for FPS\n");

		scanf("%d", &b);
		if (b == 1 || b == 2) {
			// run the f(a) somewhere after this line

		} else {
			throw("invalid entry");
		}
		}

	else{
		throw("invalid entry");
	}

	if (a == 1) {
		if (b == 1){
			printf("Type the pipe length in terms of meters:\n");
			scanf("%lf", &L);
			if (L <= 0) {
				throw("Length cannot be negative or zero");
			}
			printf("Type the density in terms of kg/m^3\n");
			scanf("%lf", &rho);
			if (rho <= 0) {
				throw("density cannot be negative or zero");
			}
			printf("Type the viscosity in terms of cP\n");
			scanf("%lf", &mu);
			mu=0.1 * mu *0.01 ;
			if (mu <= 0) {
				throw("viscosity cannot be negative or zero");
			}
			printf("Type the vapor pressure in terms of Pa\n");
			scanf("%lf", &pV);
			printf("Pick one the surfaces:type\n1 for Concrete \n2 for cast iron\n3 for galvanized iron\n4 for commercial steel\n5 for drawn tubing\n");
			scanf ("%d", &c);
			if(c == 1){
				eps= 0.3;
			}
			if(c == 2) {
				eps = 0.25;
			}if(c == 3){
				eps = 0.15;
			}if(c == 4){
				eps = 0.046;
			}if(c == 5){
				eps = 0.0015;
			}if(c <= 0 || c > 5){
				throw("invalid input");
			}

			printf("type inner diameter in terms of meters\n");
			scanf("%lf", &D);

			printf("type the volumetric flow rate in terms of m^3/s\n");
			scanf("%lf", &Q);


			printf("type the height difference between points in terms of meters\n");
			scanf("%lf", &deltaz);
			u_mean = umean(Q,D);
			printf("Umean is %f m/s\n", u_mean);
			Re= RE(D,rho,u_mean,mu);
	  	    printf("Reynolds number is %f\n", Re);
	  	    fF=f(eps, D, Re);
	  	    printf("Friction factor is %f\n", fF);
	  	    deltaP = pdrop(fF, rho, u_mean, L, D, g_SI, deltaz);
	  	    printf("Pressure drop is %f Pa", deltaP);
	  	    printf("P2 is %f Pa", deltaP + pV);

		}if (b == 2){
			printf("Type the pipe length in terms of feet:\n");
			scanf("%lf", &L);
			if (L <= 0) {
				throw("Length cannot be negative or zero");
			}
			printf("Type the density in terms of lbm/ft^3\n");
			scanf("%lf", &rho);
			if (rho <= 0) {
				throw("density cannot be negative or zero");
			}
			printf("Type the viscosity in terms of cP\n");
			scanf("%lf", &mu);
			mu= 0.01 * mu * 0.06719689;
			if (mu <= 0) {
				throw("viscosity cannot be negative or zero");
			}
			printf("Type the vapor pressure in terms of psi\n");
			scanf("%lf", &pV);
			printf("Pick one the surfaces:type\n1 for Concrete \n2 for cast iron\n3 for galvanized iron\n4 for commercial steel\n5 for drawn tubing\n");
			scanf ("%d", &c);
			if(c == 1){
				eps= 0.001;
			}
			if(c == 2) {
				eps = 0.00085;
			}if(c == 3){
				eps = 0.0005;
			}if(c == 4){
				eps = 0.00015;
			}if(c == 5){
				eps = 0.000005;
			}if(c <= 0 || c > 5){
				throw("invalid input");
			}
			printf("epsilon is %f ft\n",eps);

			printf("type inner diameter in terms of ft\n");
			scanf("%lf", &D);

			printf("type the volumetric flow rate in terms of ft^3/s\n");
			scanf("%lf", &Q);
			printf("type the height difference between points in terms of ft\n");
			scanf("%lf", &deltaz);
					u_mean = umean(Q,D);
			printf("%f %f %f %f\n", D,rho,u_mean,mu);
			printf("Umean is %f ft/s\n", u_mean);
					Re= RE(D,rho,u_mean,mu);
			printf("Reynolds number is %f\n", Re);
				    fF=f(eps, D, Re);
		    printf("Friction factor is %f\n", fF);
				    deltaP = pdrop(fF, rho, u_mean, L, D, g_FPS, deltaz);
		    printf("Pressure drop is %f psi\n", deltaP);
		    printf("P2 is %f psi\n", deltaP + pV);
		}
	}	if(a == 2) {
		if(b == 1) {
			printf("Type the pipe length in terms of meters:\n");
			scanf("%lf", &L);
			if (L <= 0) {
			throw("Length cannot be negative or zero");
			}
			printf("Type the density in terms of kg/m^3\n");
			scanf("%lf", &rho);
			if (rho <= 0) {
			throw("density cannot be negative or zero");
			}
			printf("Type the viscosity in terms of cP\n");
			scanf("%lf", &mu);
			mu=0.1 * mu *0.01 ;
			if (mu <= 0) {
			throw("viscosity cannot be negative or zero");
			}
			printf("Type the vapor pressure in terms of Pa\n");
			scanf("%lf", &pV);
			printf("Pick one the surfaces:type\n1 for Concrete \n2 for cast iron\n3 for galvanized iron\n4 for commercial steel\n5 for drawn tubing\n");
			scanf ("%d", &c);
				if(c == 1){
					eps= 0.3;
					}
				if(c == 2) {
					eps = 0.25;
				}if(c == 3){
					eps = 0.15;
				}if(c == 4){
					eps = 0.046;
				}if(c == 5){
					eps = 0.0015;
				}if(c <= 0 || c > 5){
					throw("invalid input");
				}

			printf("type inner diameter in terms of meters\n");
			scanf("%lf", &D);
			printf("type the pressure of Pa\n");
			scanf("%lf", &P);
			printf("type the height difference between points in terms of meters\n");
			scanf("%lf", &deltaz);
			deltaP=P-pV;
			Re=100000;
			int i;
			for(i=0;i<99;i++){
			fF=f(eps,D,Re);

			u_mean=umean2(D,fF,rho,L,deltaP,g_SI,deltaz);
				if(RE(D,rho,u_mean,mu)-Re <= tol){
					break;
				}
				Re= RE(D,rho,u_mean,mu);
			}
			printf("Reynolds number is %f\n", Re);
		}

		if (b == 2){
				printf("Type the pipe length in terms of feet:\n");
				scanf("%lf", &L);
				if (L <= 0) {
					throw("Length cannot be negative or zero");
				}
				printf("Type the density in terms of lbm/ft^3\n");
				scanf("%lf", &rho);
				if (rho <= 0) {
					throw("density cannot be negative or zero");
				}
				printf("Type the viscosity in terms of cP\n");
				scanf("%lf", &mu);
				mu= 0.01 * mu * 0.06719689;
				if (mu <= 0) {
					throw("viscosity cannot be negative or zero");
				}
				printf("Type the vapor pressure in terms of psi\n");
				scanf("%lf", &pV);
				printf("Pick one the surfaces:type\n1 for Concrete \n2 for cast iron\n3 for galvanized iron\n4 for commercial steel\n5 for drawn tubing\n");
				scanf ("%d", &c);
				if(c == 1){
					eps= 0.001;
				}
				if(c == 2) {
						eps = 0.00085;
				}if(c == 3){
						eps = 0.0005;
				}if(c == 4){
						eps = 0.00015;
				}if(c == 5){
						eps = 0.000005;
				}if(c <= 0 || c > 5){
				throw("invalid input");
			}
			printf("epsilon is %f ft\n",eps);
			printf("type inner diameter in terms of ft\n");
			scanf("%lf", &D);
			printf("type the pressure in terms of Psi\n");
			scanf("%lf", &P);
			printf("type the height difference between points in terms of feet\n");
			scanf("%lf", &deltaz);
			Re=100000;
			deltaP=P-pV;
			int i;
				for(i=0;i<10;i++){

				fF=f(eps,D,Re);
			//	printf("%f\n",fF);
				u_mean=umean2(D,fF,rho,L,deltaP*144*32,g_FPS,deltaz);
			//	printf("%f\n",u_mean);
					if(fabs(RE(D,rho,u_mean,mu)-Re) <= tol){
						break;
					}
				Re= RE(D,rho,u_mean,mu);
			}
			printf("Reynolds number is %f\n", Re);
			Q=u_mean*PI*D*D/4;
			printf("Flow rate is %f\n", Q);
			}
	}

  return 0;
}
