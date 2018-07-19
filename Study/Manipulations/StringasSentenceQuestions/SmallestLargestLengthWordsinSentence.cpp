#include<iostream>
using namespace std;
#include<string.h>
//#include<limits.h> //INT_MAX,INT_MIN

/*************************************************************
=>Assume maxlength and minlength as base index element of 2d array
=>Take maxword and minword arrays to store the values accordingly

  int min = strlen(y[0]); //V.V.Imp,base index of array
  int max = strlen(y[0]); //V.V.Imp,base index of array
  char maxword[20];
  char minword[20];
*************************************************************/

int main()
{
	const char *x="Global Edge is a MNC\nGlobal Edge is located in Tech Park\tTech Park is Good";
	char y[20][10]; //2d array with rows = Number of words[space+1],columns = word with max length
	int j = 0; //rows
	int k = 0; //columns

	while (*x)
	{
		if(*x == ' ' || *x == '.' || *x == '\n' || *x == '\t')
		{
			y[j][k]='\0'; //Completion of Each WORD
			j++; //Increment rows
			k=0; //Reset columns to 0

			x++; //V.V.Imp, Whenever these characters come,Move the 'x' position to next position
		}

		if(*x != '\0')
		{    
			y[j][k]= *x; //Filling the 2d array
			k++; //increment columns
		}
		x++;
	}
	y[j][k]='\0'; //Completion of Last WORD

#if 0 //Never use these macros for array,Instead we can use base index for initializing min and max value
	int min = INT_MIN;
	int max = INT_MAX;
#endif
	int min = strlen(y[0]); //V.V.Imp,base index of array
	int max = strlen(y[0]); //V.V.Imp,base index of array
	char maxword[20];
	char minword[20];
	for(int a=0;a<=j;a++) //condition check with rows only
	{
		if(strlen(y[a]) >= max)
		{
			max = strlen(y[a]);
			strcpy(maxword,y[a]); //Keep storing the maximum word always
		}
		if(strlen(y[a]) <= min)
		{
			min = strlen(y[a]);
			strcpy(minword,y[a]); //Keep storing the maximum word always
		}
	}

	cout<<"Maximum/Largest Length word is: "<<maxword<<" => "<<max<<endl;
	cout<<"Minimum/Smallest Length word is: "<<minword<<" => "<<min<<endl;
}


