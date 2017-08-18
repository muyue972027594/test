/***第一题：解析GPS报文***/
#include<stdio.h>
#include<string.h>
int main()
{
	char s[100],c1[7],c2[11],c3[2],c4[11],c5[2],c6[2],c7[3],c8[5],c9[8],
				c10[7],c11[5],c12[5];
	int i,j,count=0;
	fgets(s,100,stdin);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==',') count++;
		j=0;
		switch(count)
		{
/*			case 1:
			{
				while(1)
				{
					if(s[i+j+1]==',')
					{
						c1[j]='\0';i=i+j;break;
					} 
					c1[j]=s[i+j+1];
					j++;
				}
			}  break;
*/			case 2:
			{
				while(1)
				{
					if(s[i+j+1]==',')
					{
						c2[j]='\0';i=i+j;break;
					} 
					c2[j]=s[i+j+1];
					j++;
				}
			}  break;
			case 3:
			{
				while(1)
				{
					if(s[i+j+1]==',')
					{
						c3[j]='\0';i=i+j;break;
					} 
					c3[j]=s[i+j+1];
					j++;
				}
			}  break;
			case 4:
			{
				while(1)
				{
					if(s[i+j+1]==',')
					{
						c4[j]='\0';i=i+j;break;
					} 
					c4[j]=s[i+j+1];
					j++;
				}
			}  break;
			case 5:
			{
				while(1)
				{
					if(s[i+j+1]==',')
					{
						c5[j]='\0';i=i+j;break;
					} 
					c5[j]=s[i+j+1];
					j++;
				}
			}  break;
/*			case 6:
			{
				while(1)
				{
					if(s[i+j+1]==',')
					{
						c6[j]='\0';i=i+j;break;
					} 
					c6[j]=s[i+j+1];
					j++;
				}
			}  break;
*/		}
	}
	puts(c2);
	puts(c3);
	puts(c4);
	puts(c5);
    for(i=0;i<9;i++)
    {
        if(i<=1)
        {
            wei+=c2[i]-48;
            wei*=10;
        }
        else if(c2[i]>='0'&&c2[i]<='9')
        {
            wei1+=c2[i]-48;
            wei1*=10;
        }
    }
    for(i=0;i<10;i++)
    {
        if(i<=2)
        {
            jing+=c4[i]-48;
            jing*=10;
        }
        else if(c4[i]>='0'&&c4[i]<='9')
        {
            jing1+=c4[i]-48;
            jing1*=10;
        }
    }
    if(c3[0]=='N') printf("北纬");
    else if(c3[0]=='S') printf("南纬");
    printf(p,wei/10,wei1/100000);
    if(c5[0]=='E') printf("东经");
    else if(c5[0]=='W') printf("西经");
    printf(p,jing/10,jing1/100000);
}
