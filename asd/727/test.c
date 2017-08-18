#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch[10] = {0};
	char *p = ch;
	int num=0,*num_p = &num;
	p = "ascdefadawafawfafawawqwfagsgerethdfdbjrhfgweweedgsdfg";
	*num_p = 5;
	printf("%s\n",ch);
	printf("%s\n",p);
	printf("%d\n",num);
	printf("%d\n",*num_p);
}
