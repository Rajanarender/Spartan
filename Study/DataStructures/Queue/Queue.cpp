#include<iostream>
using namespace std;

/***************************************************************
Queue using Array
Queue using class
Queue using Single Linked list[nothing but ptr]
Queue using Stacks

NOTE: STL deque container class = Stack + Queue
*****************************************************************/

/********************************************
Queue implementation using Array,class
********************************************/

#define MAX 5
int Q[MAX];
int front = -1;
int rear = -1;

void Enqueue(int x) //In STL,this is push_front()
{
	if(rear >= MAX-1)
	{
		cout<<"Queue Overflow\n";
	}
	Q[++rear] =x;
        front = 0; //V.V.V.Imp,Since front advances by +1, when the 1st element is Enqueued
}

int Dequeue() //V.V.Imp. In STL, this is pop_front(), pop_front() erases the element but does not return it
{
	if(front <= -1)
	{
		cout<<"Queue Underflow\n";
	}
	return Q[front++];
}

int main()
{
	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
        cout<<Dequeue()<<endl;
        cout<<Dequeue()<<endl;
}

/********************************************
Queue implementation using Single Linked List
********************************************/
#if 0
struct node
{
int data;
struct node *next;
};


void Enqueue(struct node *front,struct node *rear,int newdata)
{
	struct node *newnode= (struct node*)malloc(sizeof(struct node));
	if(rear == NULL) //If Queue is Empty
	{
		front = rear = newnode; //V.V.Imp. Make front & rear point to newnode.Only for the 1st node Enqueued
                return;
	}
        rear->data = newdata;
	rear->next = newnode;
	rear = newnode;
}

int Dequeue(struct node *front,struct node *read)
{
	if(front == NULL) //If Queue is Empty
	{
		rear = NULL; //Make rear also NULL
		return -1;
	}
	struct node *temp=front;
	front = front ->next;

	int x = temp->data; //Preserve the queue data
	temp->next =NULL;
	free(temp);
	return x;
}


int main()
{
	struct node *front=NULL,*rear=NULL;
	Enqueue(front,rear,5);
	Enqueue(front,rear,6);
	Enqueue(front,rear,7);
	Enqueue(front,rear,8);
	cout<<Dequeue(front,rear);
	cout<<Dequeue(front,rear);
	cout<<Dequeue(front,rear);
	cout<<Dequeue(front,rear);
}
#endif




