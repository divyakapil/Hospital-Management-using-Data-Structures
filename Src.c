#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NULL 0
struct node
{
int bill;
char name[50];
char disease[50];
struct node *next;
};
struct node *first = NULL;
void create()
{
inti,n;
struct node *pnode,*p;
printf("Enter the number of patients:\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
pnode=(struct node*)malloc(sizeof(struct node));
if(pnode==NULL)
{
printf("memory overflow.unable to create\n");
return;
}
printf("Enter name of patient %d: ",i);
scanf("%s",pnode->name);
printf("Enter disease of patients %d: ",i);
scanf("%s",pnode->disease);
printf("Enter the bill of patient no. %d: ",i);
scanf("%d",&pnode->bill);

pnode->next=NULL;
if(first==NULL)
first=p=pnode;
else
{
p->next=pnode;
p=pnode;
}
}
}

void insertend(char name[],char disease[],int bill)
{
struct node *pnode,*p,*follow;
pnode=(struct node*)malloc(sizeof(struct node));
if(pnode==NULL)
{
printf("memory overflow.Unable to create\n");
return;
}
strcpy(pnode->name,name);
strcpy(pnode->disease,disease);
pnode->bill=bill;
p=first;
follow=NULL;

while(p!=NULL)
{
follow=p;
p=p->next;
}

follow->next=pnode;
pnode->next=NULL;
}

void deletenode(char k[])
{
struct node *p,*follow;
p=first;
follow=NULL;

while(p!=NULL)
{
if(strcmp(p->name,k)==0)
{
printf("\nDeleted details of <* %s *>\n",p->name);
break;
}
follow=p;
p=p->next;
}
if(p==NULL)
printf("Required node not found\n");
else
if(p==first)
first=first->next;
else
follow->next=p->next;
free(p);
}

void search(char k[])
{
struct node *p;
p=first;
while(p!=NULL)
{
if(strcmp(p->name,k)==0)
break;
p=p->next;
}
if(p==NULL)
printf("required node not found\n");
else
printf("\n Required details are:\n");
printf("\nName=%s\nDisease=%s\nBill=%d\n",p->name,p->disease,p->bill);
}

void traverse()
{
struct node *p;
if(first==NULL)
printf("\nList is empty\n");
else
{
printf("\nList of patients is as shown :\n");
printf("Name\t\tDisease\t\tBill\n-----------------------------------------\n");
p=first;
while(p!=NULL)
{
printf("%s\t\t%s\t\t%d\n",p->name,p->disease,p->bill);
p=p->next;
}
printf("\n");
}
}
void main()
{
char name[50],disease[50],del[50];
intk,ch;
int bill;
clrscr();
do
{
printf("\n MENU\n");
printf("1.Create a new list\n");
printf("2.Insert new patient in list\n");
printf("3.Delete a patient from list\n");
printf("4.Search details of a patient\n");
printf("5.Print the list\n");
printf("6.Exit\n");
printf("enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
create();
break;
case 2:
printf("\nenter the name of patient:");
scanf("%s",name);
printf("\nenter the name of disease :");
scanf("%s",disease);
printf("\nenter the bill of patient:");
scanf("%d",bill);
insertend(name,disease,bill);
break;
case 3:
printf("\nenter the name of patient to delete his details=");
scanf("%s",del);
deletenode(del);
break;
case 4:
printf("\nenter the name of patient to sarch his details:");
scanf("%s",name);
search(name);
break;
case 5:
traverse();
break;
case 6:
break;
}
}while(ch!=6);
getch();
}
