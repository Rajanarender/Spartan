#include<iostream>
using namespace std;

#if 0
void func(char *x)
{
	char *baseaddr=x;
	while(*x)
	{
		cout<<"Index position: , character: "<<(x-baseaddr)<<","<<*x<<endl; //arr[i]=>*x,i=>(x-baseaddr)
		x++;
	}
}

int main()
{
	char x[]="Global";
	func(x);
}
#endif

#if 1
void func(const int * m,int *const n,int k)
//void func(int m[],int n[])
{
	for(int j=0;j<k;j++)
	{
		int temp =1;
		for(int i=0;i<k;i++)
		{
			if(j!=i)
			{
				temp = temp*m[i];
                           //*(n+j)=*(n+j) * (*(m+i));
			}
		}
		//*(n+j)=temp;
		n[j]=temp;
		
              cout<<*(n+j)<<endl;
	}
}
#endif

#if 0
void func(const int *m,int *const n,int k)
{
	//int *baseaddr1=m;
	//int *baseaddr2=n;
	while(*n)
	{
               *n=1;
		while(*m)
		{
			if( (n-baseaddr2) != (m-baseaddr1) )
			{
                        *n =(*n)*(*m);
			}
			m++;
		}
		m=baseaddr1;
                cout<<*n<<endl;
		n++;
	}

}
#endif

#if 1
int main()
{
 	int arr[4]={1,2,3,4};
	func(arr,arr,4);
}
#endif


