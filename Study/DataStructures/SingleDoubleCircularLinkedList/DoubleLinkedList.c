#include<stdio.h>

//Double Linked List[DLL] is represented in C++ using list class container
//DLL does not need Extra node ptr for deleting the Nodes 
//But SLL need Extra node ptr for deleting the Nodes 
//due to which we need to Preserve the temp Node in prev Node and then traverse to the next node

struct node
{
	int data;
	struct node *next;
	struct node *prev; //Extra link
}

void Print&CountNodes(struct node *headref)
{
        struct node *temp = headref;
	int count=1;
	while(temp !=NULL)
	{
		count++;
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("%d",count);

    (or)
	int count=0;
        do
	{
		count++;
		printf("%d",temp->data);
		temp=temp->next;
	}while(temp != NULL);
	printf("%d",count);
}

void insertAtBegin(struct node *headref,int newdata)
{
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next=headref;
	newnode->prev=NULL;

	if(headref !=NULL) 
	{
		headref->prev = newnode; //V.V.Imp step
	}
	headref=newnode;
}

void insertAfterMiddle(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow= headref;
	while(fast !=NULL && fast->next !=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	struct node *newnode = (struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next = slow->next;
        newnode->prev = slow;
	slow->next = newnode;
        newnode->next->prev = newnode; //V.V.V.Imp step
}

void insertAfterNthPosition(struct node *headref)
{
	struct node *temp = headref;
	int count =1; //since temp points to head node
	while(temp->next != NULL&&count < N)
	{
		count++;
		temp = temp->next;
	}
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next = temp->next;
        newnode->prev = temp;
	temp->next = newnode;
        newnode->next->prev = newnode; //V.V.V.Imp step
}

void insertAfterEnd(struct node *headref)
{
	struct node *temp = headref;
	while(temp != NULL)
	{
		temp = temp->next;
	}
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next = NULL;//Since it is the last node
        newnode->prev = temp;
	temp->next = newnode;
}

void DeleteFirstNode(struct node *headref)
{
	struct node *temp = headref;
       
	headref = headref->next;
        headref->prev=NULL;
           //(or)
        //temp->next->prev = NULL; //headref->prev = NULL;

        temp->next = NULL; //V.V.Imp step
	free(temp);
}

void DeleteMiddleNode(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow= headref;
	//struct node *prev=NULL;
	while(fast !=NULL && fast->next !=NULL)
	{
		fast = fast->next->next;
		//prev=slow; //No need of this node,since DLL has 2links
		slow = slow->next;
	}

      //V.V.Imp step
        //prev->next = slow->next; Remove this step
	slow->prev->next = slow->next;//slow is the middle node at this point
        slow->next->prev = slow->prev;
	free(slow);
} 

void DeleteNthNode(struct node *headref)
{
	struct node *temp = headref;
	//struct node *prev=NULL;
	int count =1;//since temp points to head node
	while(temp->next != NULL&&count < N)
	{
		count++;
		//prev=temp; //Preserve the node, then traverse
		temp = temp->next;
	}
      
      //V.V.Imp step
	//prev->next=temp->next; Remove this step
          temp->prev->next = temp->next;
          temp->next->prev = temp->prev;
	  free(temp);
}

void DeleteLastNode(struct node *headref)
{
	struct node *temp = headref;
	//struct node *prev=NULL; //SLL needs Extra ptr for deletion 
	while(temp->next !=NULL)
	{
		//prev=temp; //Preserve the node, then traverse
		temp=temp->next;
	}
	//prev->next = NULL;
        temp->prev->next = NULL;
        temp->prev = NULL;
	free(temp);
}

void FindMiddleNode2ptrs(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow=headref;
	while(fast !=NULL && fast->next !=NULL) //Floyd's Cycle Detection Algorithm
	{
		fast=fast->next->next;
		slow= slow->next;
	}
	printf("%d",slow->data); //MiddleNode
}
//Time Complexity is O(n)

void FindMiddleNode1ptr(struct node *headref)
{
	struct node *temp = headref;
	struct node *mid = headref;
	int count =1;
	while(temp!=NULL)
	{
		count++;
		if(count%2==1) //Move the middle node for All odd Nodes
			mid=mid->next;

		temp=temp->next;
	}
}

void FindCircularLoop(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow=headref;
	while(fast !=NULL && fast->next !=NULL) //Floyd's Cycle Detection Algorithm 
	{
		fast=fast->next->next;
		slow= slow->next;
		if(fast == slow)
		{
			printf("Linked List is Circular,It is having Loop");
			break; //Mandatory to break this loop, or else it leads to infinite loop
		}
	}
}
//Time Complexity is O(n)

void ConvertDLLtoCLL(struct node *headref)
{
	struct node *temp=headref;
	while(temp->next != NULL)
	{
		temp =temp->next;
	}
	temp->next = headref;
        headref->prev = temp; //V.V.Imp
}

void IterativeReverseSLL(struct node *headref)
{
	struct node *temp = headref;
	struct node *x = NULL;
	while(temp != NULL)
	{
		x = temp->prev;  //Swapping
		temp->prev = temp->next;
		temp->next = x;

		temp = temp->prev; //Normally temp = temp->next, 
                                   //But in Reversal temp=temp->prev for Traversing
	}
        headref = x->prev; //V.V.Imp step
}

struct node* RecursiveReverseSLL(struct node *headref)
{
	struct node *x = headref->prev;
	headref->prev = headref->next;
	headref->next = x;

	if(headref->prev == NULL) //If condition is must to break the Recursion
		return headref;

	return RecursiveReverseSLL(headref->prev); //V.V.Imp
}

void RotateByKnodes(struct node *headref)
{

}

void Palindrome(struct node *headref)
{

}
