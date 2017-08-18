#include<stdio.h>
int main()
{
	int r;float area=100;
	for(r=10;area>=100;) { r--;area=3.14*r*r;}
	printf("%f,%d\n",area,r);
}
