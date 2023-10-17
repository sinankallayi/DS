#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int que[SIZE];
int front=0,rear=0;
void main()
{
void enque(int);
int deque();
int search(int);
int option,items,ans;
do
{
printf("\n 1.Insert \n");
printf("\n 2.Delete \n");
printf("\n 3.Search \n");
printf("\n 4.Exit \n");
printf("\n Enter your option : ");
scanf("%d",&option);
switch(option)
{
case 1:
	printf(" Item : ");
	scanf("%d",&items);
	enque(items);
	break;
case 2:
	items=deque();
	printf(" Item = %d \n",items);
	break;
case 3:
	printf(" Item to search : ");
	scanf("%d",&items);
	ans=search(items);
	if(ans!=0)
	printf(" %d found at %d \n",items,ans);
	else
	printf(" %d Not found \n",items);
	break;
case 4:
	exit(0);
}
}
while(1);
}
void enque(int items)
{
int t;
t=(rear+1)%SIZE;
if(t==front)
{
printf(" Que is full");
printf(" \n");
exit(1);
}
else
{
rear=t;
que[rear]=items;
}
}
int deque()
{
if(front==rear)
{
printf(" Que is empty");
printf(" \n");
exit(2);
}
front=(front+1)%SIZE;
return que[front];
}
int search(int items)
{
int t1,t2; 
t1=front;
t2=rear;
t1=(t1+1)%SIZE;
while(t1!=t2&&que[t1]!=items)
{
t1=(t1+1)%SIZE;
}
if(front==rear)
{
printf("Que is Empty");
exit(0);
}
if(que[t1]==items)
{
return t1;
}
else
{
return 0;
}
}
