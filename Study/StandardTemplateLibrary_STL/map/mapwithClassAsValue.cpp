#include<iostream>
using namespace std;
#include<map>

class Test
{
	string str;
	int var;

	public:
#if 1 //Default constructor,Mandatory for Explicit constructor call Test(),V.V.Imp step
        Test()
        {
         str = ' '; //space character
         var =0;
        }
#endif
	Test(string s,int num)
	{
		str=s;
		var=num;
	}

	void display() 
	{
		cout<<"Name: "<<str<<","<<" variable: "<<var<<endl;
	}
};

int main()
{
        map<int,Test>m; //class as Value
        m[0]=Test("Raja",10);
        m[1]=Test("Suri",20);
        m[2]=Test("Raja",30); //Previous same key will be overridden with this key-value pair
        m.insert( make_pair(3,Test("Raja",40)) ); //same key cannot be inserted
        m.insert( pair<int,Test>(4,Test("Ammi",50)) );
        for(map<int,Test>::iterator it=m.begin();it != m.end(); it++)
           {
             cout<<"Key is:"<<it->first;
             cout<<" Value is:";
             it->second.display(); //This func displays class members,
                                   //Do not use cout for void functions,V.V.Imp step
           }
}

