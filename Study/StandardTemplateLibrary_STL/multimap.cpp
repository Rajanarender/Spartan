#include<iostream>
using namespace std;
#include<map>


int main()
{
	multimap<char,int>m;
#if 0 //we cannot access the elements using index in multimap
	m['A'] =2;
	m['B'] =1;
	m['C'] =3;
	m['A'] =4;
#endif
	//m.insert(make_pair('A',2));
	m.insert(make_pair("AK",2));
	//m.insert(make_pair('B',1));
	m.insert(make_pair("BK",1));
	m.insert(make_pair("CK",3));
	m.insert(make_pair("AK",4));
	m.insert(make_pair("AK",10));
        m.insert(pair<char,int>("AK",20));
	m.insert(make_pair("BP",100));
	multimap<char,int>::iterator it,it1;
#if 0
       for(it=m.begin();it !=m.end();it++)
       {
          it1=it++;
        
       for(it1=m.begin();it1 !=m.end();it++)
            if((it1->first == it->first) && (m.count(it)>1) )
              {
	cout<<it->first<<"=>"<<it->second<<endl;
              }
       }
#endif


#if 1 
for(char key ="AK";key<="CK";key++)
{
	it = m.find(key);
	int count = m.count(key);
	//cout<<"count is: "<<count<<endl;
	if(count>1)
	{
		for(int i=0;i<count;i++)
		//for(int i=count;i>0;i--)
		{
			cout<<(it)->first<<"=>"<<(it)->second<<endl;
			it++;
		}
	}
}
#endif
#if 0
	for(char key='A';key<='C';key++)
	{
		pair< multimap<char,int>::iterator, multimap<char,int>::iterator > ret = m.equal_range(key);
		for( multimap<char,int>::iterator it= ret.first; it !=ret.second;it++)
		{
			cout<<it->first<<"=>"<<it->second<<endl;
		}
	}
#endif
#if 0
        multimap<char,int>::iterator it1,it2;
	for(it = m.begin();it != m.end();it++)
	{
		if( it->second == (it++)->second )
		{
			cout<<"Key having duplicate value is:"<<it->first<<endl;
                        break;
		}
	}
#endif
}
