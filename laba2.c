#include <stdio.h>
#include <math.h>
double max(double a, double b){
	if(a>b){return a;}
	else{return b;}
}
double min(double a, double b){
	if(a<b){return a;}
	else{return b;}
}
void main(){
	double x=0.0;
	double y=1.0;
	double hy=0.4;
	double hx=0.3;
	for(x;x<=1.0;x+=hx){
		for(y;y<=2.0;y+=hy){
			if(x*y<=-1.0){
                printf("x=%f, y=%f, f(x,y)=%f\n",x,y,max(exp(x),x));
                }
			if((-1.0<x*y)||(x*y<2.0)){
                printf("x=%f, y=%f, f(x,y)=%f\n",x,y,0.0);
                }
			if(x*y>=2.0){
                printf("x=%f, y=%f, f(x,y)=%f\n",x,y,min(min(x*x,cos(x)),cos(y)));
                }
		}
        y=1.0;
	}
}
