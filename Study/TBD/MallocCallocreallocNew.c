/*
#include<stdio.h>
using namespace std;
#include<string.h>

int main()
{
	char s[]="Global";
	char *p = new char[strlen(s)+1]; //1 is for NULL character
	strcpy(p,s);
	cout<<p<<endl;
        //delete p;
	//cout<<p<endl; //Error
        delete []p;
        p=NULL;//Good coding practice, to avoid Dangling ptr
}

#endif
*/

#define cpp
#include<stdio.h>
#include<string.h>

int main()
{
	char x[]="Global";
	char *p =(char*)malloc(sizeof(char));
	strcpy(p,x);
	printf("%s\n",p);

	p =(char*)malloc(sizeof(char));
        //p =(char*)realloc(p,sizeof(char));
        char y[]="Edge";
        strcpy(p,y);
	printf("%s\n",p);
        free(p);
        p=NULL;//Good coding practice, to avoid Dangling ptr
}
