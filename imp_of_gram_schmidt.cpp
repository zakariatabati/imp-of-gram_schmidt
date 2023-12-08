#include<stdio.h>
#include<math.h>
float a[20][20]={0};
float dot_prd(float *u,float *v,int n)
{
	float r=0;
	for(int i=0;i<n;i++)
		r+=v[i]*u[i];
	return r;
}
void normalization(float *u,float *v,int n)
{
	float r=0;
	for(int i=0;i<n;i++)
	{
		r+=u[i]*u[i];
	}
	r = sqrt(r);
	for(int i=0;i<n;i++)
		v[i]=u[i]/r;
} 










int main()
{
	int n,m;
	do
	{
		printf("enter the dimension of the space and the number of vectors in your family (independent) : ");
		scanf("%d%d",&n,&m);
	}while(n<=0 || m<=0);
	float u[m][n];
	float v[m][n];
	for(int i=0;i<m;i++)
	{
		printf(" enter vector  %d : ", i+1);
		for(int j=0;j<n;j++)
		{
			scanf("%f",&u[i][j]);
			a[i][j] = u[i][j];
		}
			
	}
	normalization(a[0],v[0],n);// First step
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=0;k<n;k++)
			{
				a[i][k] -= dot_prd(u[i],v[j-1],n)*v[j-1][k];
			}
		}
		normalization(a[i],v[i],n);
	}
	printf(" the vectore before Gram_schmidt : \n ");
	for(int i=0;i<m;i++)
	{
		printf(" vector %d : ",i+1);
		for(int j=0;j<n;j++)
			printf("%f ",u[i][j]);
		printf("\n");
	}
	printf(" the vectore after Gram_schmidt : \n");
	for(int i=0;i<m;i++)
	{
		printf(" vector %d : ",i+1);
		for(int j=0;j<n;j++)
			printf("%f ",v[i][j]);
		printf("\n");
	}
	
	
	
}
