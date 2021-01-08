#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include "rk4.cc"

using namespace std;

double m=940, hbarc=197.3, k=100, 
//b=0;
//b=10;
b=30;
double v(double x){

    return (1.0/2.0)*(k*pow(x,2.0))+(1.0/3.0)*(b*pow(x,3.0));    
}

double f1(double x, double y, double z, double en){

    return z;
}
double f2(double x, double y, double z, double en){

    return 2*m*y*(v(x)-en)/(pow(hbarc,2.0));
}

int main(){

    ofstream out("sch_3c.dat");
    cout.precision(6);
    cout.setf(ios::scientific);
    out.precision(6);
    out.setf(ios::scientific);   


    int i;
    
    double xi,en1,en2,en3,eps,h,xmax;

    double xi1,yi1,zi1,xi2,yi2,zi2,xi3,yi3,zi3;
    double yf1,zf1,yf2,zf2,yf3,zf3;

    double xa1[1999],ya1[1999],za1[1999];
    double xa2[1999],ya2[1999],za2[1999]; 
    double xa3[1999],ya3[1999],za3[1999];

    en1=120;
    en2=80;

do
{
    en3=(en1+en2)/2.0;

    xi=0.01;
    h=0.01;
    xmax=20.0;
    eps=0.0001;

    xi1=h;
    yi1=h;
    zi1=1.0;

    xi2=h;
    yi2=h;
    zi2=1.0;

    xi3=h;
    yi3=h;
    zi3=1.0;

    i=0;
    
    while(xi<=xmax){

        rk4(f1,f2,xi1,yi1,zi1,xmax,h,en1,yf1,zf1);
        rk4(f1,f2,xi2,yi2,zi2,xmax,h,en2,yf2,zf2);
        rk4(f1,f2,xi3,yi3,zi3,xmax,h,en3,yf3,zf3);  

        xa1[i]=xi1;
        ya1[i]=yi1; 
        za1[i]=zi1;

        xa2[i]=xi2;
        ya2[i]=yi2; 
        za2[i]=zi2;   

        xa3[i]=xi3;
        ya3[i]=yi3; 
        za3[i]=zi3;     

    xi1=xi1+h;
    yi1=yf1;
    zi1=zf1;

    xi2=xi2+h;
    yi2=yf2;
    zi2=zf2;

    xi3=xi3+h;
    yi3=yf3;
    zi3=zf3;

    xi=xi+h;
    i++;
    }

    if(ya1[1998]*ya3[1998]<0)
        en2=en3;
    else
        en1=en3;
    }
while(fabs(en2-en1)>=eps);

    cout<<"The energy is: "<<en3<<endl;

    for(i=0;i<1999;i++)out<<xa3[i]<<setw(15)<<ya3[i]<<setw(15)<<za3[i]<<endl;

    out.close();
    return 0;
}

