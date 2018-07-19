#include<iostream>
using namespace std;
#include<string.h>

/*******************************************************
Definition:[Object Creation Based on type]
We are defining an interface class for creating an object,
in which only subclasses will decide which class to get instantiated

Client does not create the objects of vehicles
It interacts with Factory class which in turn creates the objects of vehicles
Here Factory class decides which Vehicle class objects need to be created

virtual constructor is achieved using Factory Design pattern
Example:
Paytm is Factory

Transaction -Base class

Derived classes like:
Credit Card(CC)
Debit Card(DC)
Cash On Delivery(COD)

Based on the transaction type,Factory will create & implement 
Derived classes CC,DC,COD
********************************************************/

class Vehicle //Create a ptr object for this in main()
{
	public:
		virtual void func()=0;
};

class Car: public Vehicle
{
	public:
		virtual void func()
		{
			cout<<"Vehicle is Car"<<endl;
		}
};

class Bike: public Vehicle
{
	public:
		virtual void func()
		{
			cout<<"Vehicle is Bike"<<endl;
		}
};

class Factory  //Create a ptr object for this in main() 
{
	public:
		virtual Vehicle *create(const char*) = 0;
};

class subFactory:public Factory 
{
	public:
		Vehicle *create(const char *x)
		{
			if(strcmp(x,"Car") ==0)
				return new Car(); //Creation of Car
			else if(strcmp(x,"Bike") ==0)
				return new Bike(); //Creation of Bike
		}
};


int main() //This is client
{
	Factory *f;
        Vehicle *v;
        f= new subFactory;
	v = f->create("Car");
	v->func();
	v = f->create("Bike");
	v->func();
}
