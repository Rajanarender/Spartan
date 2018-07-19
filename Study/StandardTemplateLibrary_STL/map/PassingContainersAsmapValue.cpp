#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<deque>
#include<list>

#include<set>

int main()
{
#if 0 //Passing vector as Map value
	map< string,vector<int> >m;
	m["Global"].push_back(10);
	m["Edge"].push_back(20);

	map< string,vector<int> >::iterator it;

	for(it=m.begin();it !=m.end();it++)
	{
		cout<<it->first<<':';
		vector<int>v = it->second;
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i]<<endl;
		}
	}
#endif

#if 0 //Passing deque as Map value
	map< string,deque<int> >m;
	m["Global"].push_front(10);
	m["Edge"].push_front(20);

	map< string,deque<int> >::iterator it;

	for(it=m.begin();it !=m.end();it++)
	{
		cout<<it->first<<':';
		deque<int>d = it->second;
		for(int i=0;i<d.size();i++)
		{
			cout<<d.back()<<endl;
		}
	}
#endif

#if 0 //Passing list as Map value
	map< string,list<int> >m;
	m["Global"].push_front(10);
	m["Edge"].push_front(20);

	map< string,list<int> >::iterator it;

	for(it=m.begin();it !=m.end();it++)
	{
		cout<<it->first<<':';
		list<int>l = it->second;
		for(int i=0;i<l.size();i++)
		{
			cout<<l.back()<<endl;
		}
	}
#endif

#if 1 //Passing set as Map value
	map< string,set<int> >m;
	m["Global"].insert(10);
	m["Edge"].insert(20);

	map< string,set<int> >::iterator it;

	for(it=m.begin();it !=m.end();it++)
	{
		cout<<it->first<<':';
		set<int>s = it->second;
		set<int>::iterator it1;
		for(it1=s.begin();it1 !=s.end();it1++)
		{
			cout<<*it1<<endl;//V.V.V.Imp, set does not have access specifier
		}

#if 0 //this code does not work for set
		for(int i=0;i<s.size();i++)
		{
			cout<<i<<endl;
		}
#endif
	}

#endif
}
