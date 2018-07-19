#include<iostream>
using namespace std;
#include<vector>

int main()
{
        int x[]= {2,4,6,8,9,4,5,7};
	vector<int>v(x,x+8); //C++11
#if 0
	for(vector<int>::iterator it=v.begin();it !=v.end();it++)
	{
		if(*it == 1) //4th index element
		{
			//v.insert(it,100); //it ,we should pass only address/ref as parameter
                         it=v.erase(it);
		}
		cout<<*it<<endl;
	}
#endif
	while(!v.empty())
	{
		cout<<v.back()<<endl; //displays from back of array 7 5 4 9 8 6 4 2
                v.pop_back(); //this removes the elements from back side and iterates the  vector
#if 0
		cout<<v.front()<<endl; //This points to 1st element from front, so displays element 2 only 
		v.pop_front(); //Since pop_front() is non-member of vector, iteration is not possible 
#endif
	}

}
