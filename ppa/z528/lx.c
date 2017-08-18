#include<stdio.h>
float v(float x,float y,float z);
//	float v();
int main()
{
	float a=1.0,b=2.0,c=3.0;
	printf("%f\n",v(a,b,c));
}
float v(float x,float y,float z)
{
	return(x*y*z);
}
