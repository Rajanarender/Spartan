#include <iostream>
#include <string>
using namespace std;

/*********************************************
Adapter Design Pattern:
Adapter class inherited from only Target[public]

=>Converting the interface of a class to other interface which the client want

Here incompatiable interfaces are Target,Adaptee
They work together with the help of Adapter class
NOTE: client(main()) interacts only with the Target class
Target is public inheritance,Adaptee is private inheritance

Adapter makes classes of different interfaces to work together
class Target
class Adaptee
class Adapter::Target
*********************************************/

class Target
{
	public:
		virtual string operation() = 0;
};

class Adaptee
{
	public:
		string method() 
		{
			return "Adapter Pattern"; 
		}
};

class Adapter : public Target
{
	Adaptee &obj;
	public:
	Adapter(Adaptee &a) : obj(a) //Initializer list mandatory for reference
	{
	}

	string operation()
	{
		return obj.method();
	}
};

void f(Target &t) //Local function
{
	cout << t.operation();
}

int main()
{
	Adaptee x;
	// adaptation
	Adapter ad(x);
	f(ad); //Target->Adapter func->adpatee func
	return 0;
}
