#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>

using namespace std;

double f1(double, double, double, double);
double f2(double, double, double, double);

double rk4
(
double (*f1)(double, double, double, double),
double (*f2)(double, double, double, double), 
double xi, 
double yi, 
double zi,
double xmax, 
double h, 
double en, 
double& yf, 
double& zf
)

{
double k1,k2,k3,k4,l1,l2,l3,l4;

k1=h*f1(xi,yi,zi,en);
l1=h*f2(xi,yi,zi,en);

k2=h*f1(xi+h/2.0,yi+k1/2.0,zi+l1/2.0,en);
l2=h*f2(xi+h/2.0,yi+k1/2.0,zi+l1/2.0,en);

k3=h*f1(xi+h/2.0,yi+k2/2.0,zi+l2/2.0,en);
l3=h*f2(xi+h/2.0,yi+k2/2.0,zi+l2/2.0,en);

k4=h*f1(xi+h,yi+k3,zi+l3,en);
l4=h*f2(xi+h,yi+k3,zi+l3,en);

yf=yi+(1.0/6.0)*(k1+2.0*(k2+k3)+k4);
zf=zi+(1.0/6.0)*(l1+2.0*(l2+l3)+l4);

return 0;
}