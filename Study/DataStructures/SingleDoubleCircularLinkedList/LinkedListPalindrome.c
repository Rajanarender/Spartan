#if 0
#include<iostream>
using namespace std;
#endif

#include<stdio.h>
#include<stdlib.h>

#if 0
void func(char *x,struct node*head)
{
	struct node *temp=head;
	while(temp !=NULL)
	{
		x=temp->data;
		temp= temp->next;
		x++;
	}
	*x="\0";
}


int main()
{
	char x[];
	func(x,head);//copy each node data to char array
        cout<<x<<endl;
}
#endif

struct node
{
	char data;
	struct node *next;
};

void insert(struct node *headref,char newdata)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->next = headref;
	headref = newnode;
}

void display(struct node *headref)
{
	struct node *temp=headref;
	while(temp != NULL)
	{
                printf("Im here\n");
                printf("%c",temp->data);
                //cout<<"Im here"<<endl;
		//cout<<temp->data<<endl;
		temp = temp->next;
	}
}

int main()
{
	struct node *head= NULL;
	insert(head,'a');
	insert(head,'b');
	insert(head,'c');
	insert(head,'b');
	insert(head,'a');
	display(head);
}


