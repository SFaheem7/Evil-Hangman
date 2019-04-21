#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std;
void Readfile(string file_name, string dict[],int no_of_words){
	fstream fp;
	string text;
	int c=0;
	fp.open(file_name,ios::out|ios::in);
	while (!fp.eof())
	{
		getline(fp,text);
		dict[c]=text;
		c++;
	}
	for(int i=0;i<no_of_words;i++)
	{
		cout<<dict[i]<<endl;
	}
	fp.close();
}
void RemoveWords(string dict[],char input,int num_words){
	for(int i=0;i<num_words;i++)
	{
		stringstream ss;
		string cmp;
		string text = dict[i];
		int len = text.length();
		for(int j=0;j<len;j++)
		{
			ss<<input;
			ss>>cmp;
			if(text.substr(j,1)==cmp)
			{
				dict[i]="";
				break;
			}

		}
		if(dict[i]!=""){
			cout<<dict[i]<<endl;
		}
	}

}
int main(int argc,char *argv[])
{
	const int x = atoi(argv[2]);
	string file_name = argv[1];
	string dict[x];
	if(atoi(argv[3])==1)
    {

		Readfile(file_name,dict,x);
	}
	else if (atoi(argv[3])==2)
	{
		srand (time(NULL));
		int num = rand() % 4 + 3;
		cout<<"Word Length : "<<num<<endl;
		char input;
		cout<<"Enter a Character : ";
		cin>>input;
		fstream fp;
		string text;
		int c=0;
		fp.open(file_name,ios::out|ios::in);
		while (!fp.eof())
		{
			getline(fp,text);
			dict[c]=text;
			c++;
		}
		fp.close();
		int num_word = atoi(argv[2]);
		if(input < 'a'|| input >'z')
		{
			while(input < 'a'|| input >'z'){
			cout<<"You have entered two characters. Don't try to be cheeky play by the rules. TRY AGAIN."<<endl;
			cout<<"Enter a character : ";
			cin>>input;

		}
		}
			
			RemoveWords(dict,input,num_word);
	}
	else if (atoi(argv[3])==3)
	{

		srand (time(NULL));
		int num = rand() % 4 + 3;
		cout<<"Word Length : "<<num<<endl;
		string input;
		char insert;
		stringstream op;
		fstream fp;
		string text;
		int c=0;
		fp.open(file_name,ios::out|ios::in);
		while (!fp.eof())
		{
			getline(fp,text);
			dict[c]=text;
			c++;
		}
		fp.close();
		int num_word = atoi(argv[2]);
		for(int i = 5;i>0;i--){

		cout<<"You have "<<i<<" guesses remaining"<<endl;
		cout<<"Enter a Character : ";
		cin>>input;
		if(input.length()>1)
		{
			while(input.length()>1){
			cout<<"You have entered two characters. Don't try to be cheeky play by the rules. TRY AGAIN."<<endl;
			cout<<"Enter a character : ";
			cin>>input;

		}
	}
		
		
			op<<input;
			op>>insert;
		
		
				
			RemoveWords(dict,insert,num_word);
		}
		for(int p=0;p<atoi(argv[2]);p++)
		{
			if(dict[p].length()==num)
			{
				c=p;
				break;
				
			}
		}
		cout<<"You lose because the word was : "<<dict[c];
	}
	
	return 0;

}