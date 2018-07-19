#include<iostream>

/**************************************************
namespace is used to avoid the name clashes b/w the names of variables,functions,classes used in file 
with the names present in libraries
NOTE: namespace can have variables,functions,classes as its members

syntax:
namespace X
{

}

X::membername //to access any member
 
difference b/w class and namespace:
class with same name cannot be redeclared
class should have name

namespace with same name can be redeclared
namespace need not have name[unnamed namespace]
****************************************************/

namespace A
{
	int x=10;
	void func()
	{
		std::cout<<x;
	}

	class Test
	{
		int k;
		public:
		Test():k(80)
		{}
		void func1()
		{
			std::cout<<k;
		}

	};//End of class Test
}

//int x=10; //redeclaration error, to avoid this move it to namespace
int x =10;

namespace A //namespace can be redeclared
{
	int y =20;
}

namespace //unnamed namespace 
{
	int z =30;
}

int main()
{
	std::cout<<A::x; //accessing variable present in namespace
	std::cout<<x;
	std::cout<<A::y;
	std::cout<<::z;
	A::func();
	A::Test t; //class Test is a member of namespace A
	t.func1();
}
