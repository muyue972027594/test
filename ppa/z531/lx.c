#include<stdio.h>
void main()
{
    float v[6];int a=0,b=3;
	while(a<5)
	{
    printf("输入五个数\n");
	scanf("%f",&v[a]);
	a++;
	}
	printf("%f,%f,%f,%f,%f\n",v[0],v[1],v[2],v[3],v[4]);
}
/*int v(float a,float b)
{
	return a+b;
}*/
