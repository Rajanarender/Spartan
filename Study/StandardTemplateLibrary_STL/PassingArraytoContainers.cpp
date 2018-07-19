#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int x[]={2,4,6,8};
	vector<int>v(x,x+4);
	for(int i=0;i<4;i++)
	{
		cout<<v[i]<<endl;
	}
       
        //deque<int>d(x,x+4);
}
