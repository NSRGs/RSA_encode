#include<stdio.h>
#include<string.h>
#include<math.h>
void main()
{
	int p,q,n,m,e,d,lenth,i,j,sum;
	int b[128],c[128],dic[128];
	char a[128];
	printf("p,q:\n");
	scanf("%d,%d",&p,&q);
	//printf("%d,%d\n",p,q);
	e=2;
	m=p*q;
	n=(p-1)*(q-1);
	//printf("%d,%d,%d\n",e,n,m);
	while(1)
	{
		if(n%e==0)
			e++;
		else
			break;
	}
	//printf("%d\n",e);
	for(d=1;d*e%n!=1;d++);
	printf("KU=(%d,%d),KR=(%d,%d)\n",e,m,d,m);
	printf("Please pirnt yours what you want to decode:\n");
	scanf("%s",a);
	//printf("%s\n;",a);
	lenth=strlen(a);
	//printf("%d\n",lenth);
	/*for(i=0;i<lenth;i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");*/
	for(i=0;i<lenth;i++)
	{
		b[i]=a[i];
		dic[i]=b[i]/m;
		b[i]=b[i]-48;
		//printf("%d\n",dic[i]);
	}
	/*for(i=0;i<lenth;i++)
		printf("%d\n",b[i]);*/
	for(i=0;i<lenth;i++)
	{
		sum=1;
		for(j=1;j<=e;j++)
		{
			sum=sum*b[i];
			//printf("%d\n",sum);
		}
		c[i]=sum%m;
	}
	for(i=0;i<lenth;i++)
		printf("%d",c[i]);
	printf("\n");
	for(i=0;i<lenth;i++)
	{
		sum=1;
		for(j=1;j<=d;j++)
		{
			sum=sum*c[i];
			//printf("%d\n",sum);
		}
		c[i]=sum%m+m*(dic[i]-1)+48;
		if(c[i]>122)
			c[i]=c[i]-33;
	}
	for(i=0;i<lenth;i++)
	{
		printf("%c",c[i]);
	}
	printf("\n");
}