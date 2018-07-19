#include<stdio.h>

//Single Linked List[SLL] is represented in C++ using forward_list class container


Pending:
a->bc->dc->b->a,Prove this is a Palindrome //Ans: each node data concates to a string array

struct node
{
	int data;
	struct node *next;
};

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
	}while(temp !=NULL);
	printf("%d",count);
}

void insertAtBegin(struct node *headref,int newdata)
{
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next=headref;
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

	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next =slow->next;
	slow->next=newnode;
}

void insertAfterNthPosition(struct node *headref)
{
	struct node *temp = headref;
	int count =1;//since temp points to head node
	while(temp->next != NULL&&count < N)
	{
		count++;
		temp = temp->next;
	}
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next = temp->next;
	temp->next = newnode;
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
	temp->next = newnode;
}

void DeleteFirstNode(struct node *headref)
{
	struct node *temp = headref;
	headref =headref->next;
        temp->next = NULL; //V.V.Imp step
	free(temp);
}

void DeleteMiddleNode(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow= headref;
	struct node *prev=NULL;
	while(fast !=NULL && fast->next !=NULL)
	{
		fast = fast->next->next;
		prev=slow; //Preserve the node, then traverse
		slow = slow->next;
	}
	prev->next = slow->next;//slow is the middle node at this point
	free(slow);
} 

void DeleteNthNode(struct node *headref)
{
	struct node *temp = headref;
	struct node *prev=NULL;
	int count =1;//since temp points to head node
	while(temp->next != NULL&&count < N)
	{
		count++;
		prev=temp; //Preserve the node, then traverse
		temp = temp->next;
	}
	prev->next=temp->next;
	free(temp);
}

void DeleteLastNode(struct node *headref)
{
	struct node *temp = headref;
	struct node *prev=NULL; //SLL needs Extra ptr for deletion 
	while(temp->next !=NULL)
	{
		prev=temp; //Preserve the node, then traverse
		temp=temp->next;
	}
	prev->next = NULL;
	free(temp);
}


void FindIntersection/MergePoint(struct node *headref) //Using Floyd's Algorithm
{
//clue: Join the end node with start node of shorter linked list 
//to form the circular loop with lesser nodes,to achieve less time complexity
//After finding the intersection point,break the link b/w start and end node of shorter linked list

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
        
        while(headref->data != slow->data) //Keep comparing both the nodes, by the end of this loop both the nodes data will match
             {
               headref = headref->next;
               slow = slow->next;
             }  
            print("The Intersection/Merge point of 2 Linked lists is %d",slow->data);//headref->data 
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
		if(count%2==1)
			mid=mid->next;

		temp=temp->next;
	}
}

//The below function Takes MORE Time complexity, 
//since fastptr and slowptr may not meet in fewer iterations when the loop is having more Nodes say 1Lakh nodes
void FindCircularLoopNRemoveLoop(struct node *headref) 
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

	struct node *slowprev = NULL;
	while(headref->data != slow->data) //Keep comparing both the nodes, by the end of this loop both the nodes data will match
	{
		headref = headref->next;
		slowprev = slow; //Preserve slow ptr, then traverse
		slow = slow->next;
	}
           slowprev->next = NULL; //Disconnect slowprev from the intersection pt to break the circular loop
}

//The below takes LESS time irrespective of Nodes in the loop
//Time Complexity O(n) ,Hast Table Implementation
void DetectLoop(struct node* head)
//bool DetectLoop(struct node* head)
{
	unordered_set<node*>s; //Works in C++11 only
	while(head != NULL)
	{
		if(s.find(head) != s.end()) //finding if the node is repeated 
		{
			cout<<"Loop is present,since Node is repeated\n";
                        //return true;
			break;
		}

		s.insert(head); //Inserting/Loading the nodes into Hash table[unordered_set]
		head= head->next;
	}
      //return false;
}

//This Works only when the Length/Total no. of nodes in SLL is given 
void FindNthPosNodefromEndofSLL(struct node *headref) 
{
	struct node *temp = headref;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		if(count == (L-Npos+1)) //L is length/total no. of nodes in SLL
		{
			cout<<"Node data present at Nth position from End of SLL is:"<<temp->data;
                        break;
		}
		temp = temp->next;
	}
}

//This Works when the Length/Total no. of nodes in SLL is NOT given
void FindNthPosNodefromEndofSLL(struct node *headref)
{
	struct node *fast = headref;
	struct node *slow = headref;
        int count = 0;
        
        while(fast !=NULL && count< Npos) //Moving the fast ptr by Npos Nodes
        {
         count++;
         fast= fast->next;
        }
        while(fast != NULL) //Now Moving fast ptr & slow ptr by each node so that the distance b/w them remains the same
        {
               fast = fast->next
               slow = slow->next;
        }
        cout<<"Node value at Nth position from End of Linked List is:"<<slow->data;
}

void ConvertSLLtoCLL(struct node *headref)
{
	struct node *temp=headref;
	while(temp->next != NULL)
	{
		temp =temp->next;
	}
	temp->next=headref;
}

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void PairwiseSwap(struct node *headref)
{
	struct node *temp= headref;
	while(temp !=NULL && temp->next !=NULL)
	{
		swap(&(temp->data),&(temp->next->data));
		temp = temp->next->next; //V.V.Imp Step
	}
}
//Time Complexity is O(n)

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void SelectionSort(struct Node* headref) //Sorting SLL using Selection Sort
{
	struct node *min;
	for(struct node *i=headref; i->next != NULL; i=i->next) //Use '='operator for 3sections,V.V.Imp step
	{
		min = i;
		for(struct node *j=i->next; j != NULL; j=j->next) //*j=i->next, Use '='operator for 3sections, V.V.Imp step
		{
			if(j->data < min->data) //V.Imp condition
				min = j;
		}
		swap(i->data,min->data); //instead of reference,we can use directly,since it is node ptr address inbuilt
		//swap(&i->data,&min->data);
	}
}
//Time Complexity is O(n2),nsquare

void MinMaxNodes(struct node *headref)
{
	struct node *temp = headref;
	int max=INT_MAX; //(Max value of integer data type) INT_MAX value is 32767, #include<limits.h>
	int min=INT_MIN; //(Min value of integer data type) INT_MIN value is -32767. #include<limits.h>

	while(temp != NULL)
	{
		if(temp->data > max)
		{
			max= temp->data;
		}
		else if(temp->data < min)
		{
			min= temp->data;
		}

		temp= temp->next;
	}
	printf("Maximum Node value in Single linked list is: %d\n",max);
	printf("Minimum Node value in Single linked list is: %d\n",min);
} 

void SwapNodeLinksNotNodeData(struct node *headref) //Swap 2nodes using links not data
{
	//i/p:10->15->12->13->20->14, Given X= 15,Y=20
	//o/p:10->20->12->13->15->14

	while(curX != NULL && curX->data != X) //Traversing till X
	{
		prevX=curX; //saving prev and then traversing
		curX=curX->next;
	}

	while(curY != NULL && curY->data != Y) //Traversing till Y
	{
		prevY=curY; //saving prev and then traversing
		curY=curY->next;
	}

	if(prevX != NULL) 
	{
		prevX->next = curY; //V.Imp step ,Changing the links
	}
	else
	{
		*headref = curY; //V.V.Imp step
	}

	if(prevY != NULL)
		prevY->next = curX; //V.Imp step,Changing the links

	swap(curX->next,curY->next); //Swapping the 2nodes links only,not data
}

void DupNodesCount&RemovalSLL(struct node *headref) //Sorted Linked List
{
	struct node *temp=headref;
	struct node *dup=NULL;
	int count=0;
	while(temp !=NULL && temp->next !=NULL)
	{
		if(temp->data == temp->next->data) //If data matched,Delete the duplicate
		{
			dup = temp->next;
			temp->next = dup->next; //Form the link before deleting the node
			free(dup);
			count++;
		}
		else // If node data is not matched then keep traversing
			temp=temp->next;
	}
	printf("%d",count); //Counts the no. of duplicate nodes 
}
//Time Complexity is O(n)

void DupNodesCount&RemovalUnSLL(struct node *headref) //Unsorted Linked List
{
	struct node *temp1=headref;
	struct node *temp2=NULL;
	int count=0;
	while(temp1 != NULL && temp1->next !=NULL)
	{
		temp2=temp1;  //V.V.V.Imp step 
		while(temp2->next!=NULL)
		{
			if(temp1->data == temp2->next->data)
			{
				dup = temp2->next;
				temp2->next = dup->next; //temp2->next=temp2->next->next;
				free(dup);
                                count++;
			}
			else
				temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	printf("%d",count);
}
//Time Complexity is O(n2)

void DeleteAltNodes(struct node *headref)
{
	struct node *alt=NULL;
	while(temp != NULL && temp->next != NULL)
	{
		alt=temp->next;
		temp->next=alt->next;
		free(alt);
		temp = temp->next; //For traversing 
	}
}  
//Time Complexity is O(n)

void DeleteSinglePtrtoNode(struct node *headref)
{
	//We have the copy the data and link of next node to ptr pointing Node
	ptr->next=ptr->next->next;
	ptr->data=ptr->next->data;
	free(ptr->next);
}

void IterativeReverseSLL(struct node *headref)
{
	struct node *temp = headref;
	struct node *y =NULL; //next Node
	struct node *x = NULL; //prev Node
	while(temp != NULL)
	{
		y = temp->next;
		temp->next = x; //temp->next should be made NULL for the 1st node
		x = temp; //For Traversing
		temp = y; //For Traversing
	}
	headref = x; //head node pointing to the prev Node
}

void RecursiveReverseSLL(struct node *headref) //Recursive Reverse with void
{
	if(headref->next == NULL)
	{
         return; //V.V.Imp
	}
	Recursive(headref->next);
	headref->next->next = headref; //V.V.Imp
	headref->next = NULL; //V.V.Imp
}

struct node* RecursiveReverseSLL(struct node *headref) //Recursive Reverse with node* return type
{
	if(headref->next == NULL)
	{
         return headref;
	}
	struct node *temp = Recursive(headref->next);
	headref->next->next = headref; //Making the last node connect to the previous node using this line of code
	headref->next = NULL;// Making the previous node link as NULL,since we are reversing the linked list
        return temp;
}

void RotateByKnodes(struct node *headref)
{
	//i/p:1->2->3->4->5
	//o/p:4->5->1->2->3
	struct node *temp1 = headref;
	while(temp1 != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = headref; //Making the last node connect with head, forming circular loop

	struct node *temp2 = headref;
	while(temp2 != NULL && count <K)
	{
		count++;
		temp2 = temp2->next;
	}
	temp2->next = headref; //Making Kth node next as head
	temp2->next = NULL; //Breaking the Kth node link with head 
}

**************************************************************************
a->b->c->d->c->b->a,Prove this is a Palindrome without using string API's 
**************************************************************************

bool isPalindromeCheck(struct node *x, struct node *y)
{
	while(x && y)
	{
		if(x->data != y->data) //If nodes data is not same, Not Palindrome 
		{
			return false; //V.V.Imp
		}
		x=x->next;
		y=y->next;
	}
	return true; //V.V.Imp,Since all the nodes data is same, Linked list is a Palindrome
}

void Palindrome(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow=headref;
	while(fast !=NULL && fast->next !=NULL) //Floyd's Cycle Detection Algorithm 
	{
		fast=fast->next->next;
                slow_prev = slow; //Preserve the slow ptr and then traverse
		slow= slow->next;
	}
        slow_prev->next = NULL; //V.V.Imp,Disconnect the nodes before middle node

#if 1  //for Odd no. of Nodes
	struct node *mid = NULL;
	if(fast != NULL) 
	{
		mid = slow;
		slow = slow->next;
                mid->next = NULL; //V.V.Imp,Disconnect the middle node from 2nd half;
	}
#endif

	IterativeReverseSLL(&slow); //Reverse the 2nd half
	if( isPalindromeCheck(headref,slow) == true) 
	{
	cout<<"Given Linked List is a Palindrome\n";
	}
	else
	{
	cout<<"Given Linked List is not a Palindrome\n";
	}

	IterativeReverseSLL(&slow); //Re-Reverse the 2nd half Again to get back the original 2nd half

#if 1  // For both Odd and Even No. of Nodes
	if(mid != NULL) //for Odd No. of Nodes
	{
	slow_prev->next = mid;
	mid->next = slow; 
	}
	else //for Even No. of Nodes
	{
	slow_prev->next = slow;
	}    
#endif

#if 0 //Only for Even No. of Nodes
	slow_prev->next = slow;
#endif
}

struct node* Merge2SortedLinkedLists(struct node *head1,struct node *head2)
{
	struct node *sort;
	struct node *shead = sort; //preserve sort to a node,making it as head node
	//Here sort keeps traversing in the below code, so preserving it in prior

	if(head1 != NULL && head2 != NULL) //Intially sort to point to one linked list among the two
	{
		if(head1->data <= head2->data)
		{
			sort = head1;
			head1 = head1-next;
		}
		else
		{
			sort = head2;
			head2 = head2->next;
		}
	}

	while (head1 != NULL && head2 != NULL) //Keep traversing in both the Linked lists
	{
		if(head1->data <= head2->data)
		{
			sort->next = head1; //V.V.Imp step
			sort = head1;
			head1 = head1-next;
		}
		else
		{
			sort->next = head1; //V.V.Imp step
			sort = head2;
			head2 = head2->next;
		}
	}

#if 1 //If Extra nodes are present in linked list2 and linked list1
	if(head1 == NULL) //V.V.Imp step, head1 is not having any data
		sort->next = head2;

	if(head2 == NULL) //V.V.Imp step, head2 is not having any data
		sort->next = head1;
#endif 
	return shead;
}

struct node* insertNode(int data)
{
	struct node* Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->data=newdata;
	Newnode->next=NULL;
	return Newnode;
}

//Addition of linked lists is head to head,from Left side to Right side
//Whereas Normal Numbers addition is from from Right side to Left side
struct node* AdditionOfNodesin2SLLists(struct node *head1,struct node *head2)
{
	int sum;
	int carry=0;
	struct node *temp,*temp1;
        struct node *temphead =temp;  //preserve temp to a node,making it as head node
	//Here temp keeps traversing in the below code, so preserving it in prior

	while(head1 !=NULL || head2 !=NULL) //V.V.Imp, Any one of the linked lists should have data
	{
		sum = carry+(head1?head1->data:0)+(head2?head2->data:0);
		carry = (sum>10)?1:0;
		sum = sum%10;
		temp=insertNode(sum); //Node having sum as data

#if 1 //for forming linked lists with sum as data           
		temp1->next=temp;
		temp1=temp; //for traversing
#endif                

		if(head1 != NULL) //Traverse if node is present
			head1 = head1->next;
		if(head1 != NULL) //Traverse if node is present
			head2 = head2->next;
	}
	if(carry>0) //If carry is still present,even after completion of head1->data,head2->data
	{
		temp=insertNode(carry);//Node having carry as data
	}
	return temphead;
}

int main()
{
	struct node *head = NULL;
	insertAtBegin(head,5);
	insertAtBegin(head,6);
	while(head->next)
	{
		printf("%d",head->data);
		head = head->next;
	}
}


