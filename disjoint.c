#include<stdio.h>
#include<stdlib.h>
typedef struct
{ 
int value;
struct rep *repptr;
struct node *next;
}node;


//structure to rep header node of linked rep of set
typedef struct
{ 
node *head;
node *tail;
}rep;

//structure to store key and object node
typedef struct
{ 
int key;
node *obj_node_ptr;
struct noaddr *next;
}noaddr;
noaddr *ndr=0;

void makeset(int a)
{
noaddr *t=(noaddr*)malloc(sizeof(noaddr));
rep *newset=(rep*)malloc(sizeof(rep));  //create new set
node *n=(node*)malloc(sizeof(node));
n->value=a;
n->repptr=newset;   //filling values
n->next=0;

newset->head=newset->tail=n;  //initialise head and tail

t->obj_node_ptr=n;
t->key=a;
t->next=ndr;
ndr=t;
}



//function to return pointer of rep(header node) of a set containing x

rep *find(int x)
{
noaddr *t=ndr;
while(t->key!= x && t!=0)
t=t->next;
return t->obj_node_ptr->repptr;
}



void unionset(int key1, int key2)
{
rep *set1,*set2;
node *t1;
set1=find(key1);
set2=find(key2);
if (set1==set2)
printf("\n %d and %d belongs to same set",key1,key2);
else
{
	t1=set2->head;
	while(t1!=0)
	{
	t1->repptr=set1;
	t1=t1->next;
	}
	set1->tail->next=set2->head;
	set1->tail=set2->tail;

}
free(set2);
}

//function to display the set
void display_set(int a)
{
rep *r;
node *t;
r=find(a);
t=r->head;
printf("\nset members in %d=",a);
while(t!=0)
{
	printf("%d,",t->value);
	t=t->next;
}
}


void main()
{

makeset(10);
makeset(20);
makeset(30);
makeset(40);
makeset(50);
printf("find(10)=%x",find(10));
printf("\n");
printf("find(20)=%x",find(20));
printf("\n");
printf("find(30)=%x",find(30));
printf("\n");
printf("find(40)=%x",find(40));
printf("\n");
unionset(20,30);
display_set(20);
printf("\n after union of 20 and 30 find(20)=%x \n",find(20));
unionset(10,40);
display_set(10);
printf("\n after union of 10 and 40 find(40)=%x \n",find(40));
unionset(20,40);
display_set(40);
printf("\n after union of 20 and 40 find(40)=%x \n",find(40));
}

