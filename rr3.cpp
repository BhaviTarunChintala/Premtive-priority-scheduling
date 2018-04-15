#include<stdio.h>
#include<string.h>
int item2;
int front=-1;
int rear=-1;
int q=0;
int queue[100];
void insertion(int);
void display();
int main()
{
int n,pr[100],Bu[100],Ar[100],Bu2[100],min1,val=0,arr[100],min,max,max2,loc=0,loc2=0,count[100],count2=0,count3=0;
int Pno[100];
char th[100];
printf("enter number of process\t");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
count[i]=0;
Pno[i]=i;
printf("enter priority for P%d\n",i);
scanf("%d",&pr[i]);
printf("enter Burst time for P%d\n",i);
scanf("%d",&Bu[i]);
Bu2[i]=Bu[i];
printf("enter Arrival time for P%d\n",i);
scanf("%d",&Ar[i]);
}
for(int i=0;i<=n;i++)
{
if(Ar[i]==val && i!=n)
{
min=Ar[0];
for(int k=1;k<n;k++)
{
	if(Ar[k]<min)
	{
		min=Ar[k];
		loc=k;
	}
}
if(Bu[loc]>10)
{	
count[loc]=count[loc]+10;
Bu[loc]=Bu[loc]-10;
item2=Pno[loc];
insertion(item2);
}
else
{
count[loc]=count[loc]+Bu[loc];
Bu[loc]=0;
item2=Pno[loc];
insertion(item2);
}
for(int k=0;k<n;k++)
{
max=pr[0];
loc2=0;
for(int j=1;j<n;j++)
{
	if(pr[j]>max && Bu[j]>0)
	{
		max=pr[j];
		loc2=j;
	}
}
if(k==0)
{
count[loc2]=Bu[loc2]+count[loc];	
count3=count[loc2];
}
else
{
count[loc2]=Bu[loc2]+count3;
count3=count[loc2];
}
while(Bu[loc2]>0)
{

if(Bu[loc2]>10)
{
Bu[loc2]=Bu[loc2]-10;
item2=Pno[loc2];
insertion(item2);
}
else
{
Bu[loc2]=0;
item2=Pno[loc2];
insertion(item2);
}
}
}
break;
}
if(i==n)
{
item2=-1;
insertion(item2);
min=Ar[0];
loc=0;
for(int k=1;k<n;k++)
{
	if(Ar[k]<min)
	{
		min=Ar[k];
		loc=k;
	}
}
if(Bu[loc]>10)
{	
count[loc]=min+10;
Bu[loc]=Bu[loc]-10;
item2=Pno[loc];
insertion(item2);
}
else
{
count[loc]=min+Bu[loc];
Bu[loc]=0;
item2=Pno[loc];
insertion(item2);
}
for(int k=0;k<n-1;k++)
{
max=pr[0];
loc2=0;
for(int j=1;j<n;j++)
{
	if(pr[j]>max && Bu[j]>0)
	{
		max=pr[j];
		loc2=j;	
	}
}
if(k==0)
{
count[loc2]=Bu[loc2]+count[loc];
count3=count[loc2];
}
else
{
count[loc2]=Bu[loc2]+count3;
count3=count[loc2];
}
while(Bu[loc2]>0)
{
if(Bu[loc2]>10)
{
Bu[loc2]=Bu[loc2]-10;
item2=Pno[loc2];
insertion(item2);
}
else
{
Bu[loc2]=0;
item2=Pno[loc2];
insertion(item2);
}
}
}
}	
}
printf("PR	BR	AR	CT	TAT	WT");
for(int l=0;l<n;l++)
{
	printf("\n%d	%d	%d	%d	%d	%d\n",pr[l],Bu2[l],Ar[l],count[l],count[l]-Ar[l],count[l]-Ar[l]-Bu2[l]);
}
max2=count[0];
for(int m=1;m<n;m++)
{
	if(max2<count[m])
	{
		max2=count[m];
	}
}
printf("\nCPU utilisation rate\n");
printf("%f",(float)n/max2);
display();
}
void insertion(int item)
{
	if((front==1&&rear==100)||(front==rear+1))
	{
		printf("overflow\n");
		return;
	}
	else if(rear==100)
	{
		rear=0;
	}
	else if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear=rear+1;
	}
	queue[rear]=item;
}
void display()
{
	printf("\nGantt chart\n");

	while(front!=rear+1)
	{
		if(queue[0]==-1)
		{
			if(q==0)
			{
				front=front+1;
				printf("IDLE_task ");
			}
			q=q+1;
			printf("P%d ",queue[front]);
			front=front+1;
		}
		else
		{
			printf("P%d ",queue[front]);
			front=front+1;
		}
	}
}



