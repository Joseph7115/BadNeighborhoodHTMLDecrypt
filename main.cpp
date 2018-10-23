#include <iostream>
#include <cmath>
#include <time.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;

void solveObf(int erp[]);

int main(){
	
int erp[1500]={0};

string fileName;

cout<<"Debugging the Obfuscatred Code Produced By\n";
cout<<"Bad Neighborhood - URL: http://www.bad-neighborhood.com/htmlhashing.htm\n";
cout<<"Joseph Haley - 2018\n";
cout<<"Please enter the file to be decrypted:";
cin>>fileName;
ifstream toDec;
toDec.open(fileName);
string inp;
string s;
int counter=0;
int value=0;
if(toDec.is_open()){
	toDec.ignore(1000,'\n');
	while(!toDec.eof()){

		getline(toDec, inp);
		counter++;
		if(counter<10)
			value=1;
		else if(counter<100)
			value=2;
		else if(counter<1000)
			value=3;
		

		if((inp.find("erp[")!=std::string::npos)
			&&(inp.find("tmp")==std::string::npos)){
			inp.erase(inp.begin(),inp.begin()+8+value);
			inp.erase(inp.end()-1,inp.end());
			erp[counter]=stoi(inp);
			s.append(inp);	

		}

	}
}

toDec.close();
solveObf(erp);

return 0;
}

void solveObf(int erp[]){
	string em="";
	int temp;
	for(int i=0;i<723;i++){
		temp=erp[i];
		if(floor((temp/pow(256,3)))>0){
			em +=char(floor((temp/pow(256,3))));
		}
		temp=temp-(floor((temp/pow(256,3)))*pow(256,3));
		if(floor((temp/pow(256,2)))>0){
			em +=char(floor((temp/pow(256,2))));
		}
		temp=temp-(floor((temp/pow(256,2)))*pow(256,2));
		if(floor((temp/pow(256,1)))>0){
			em +=char(floor((temp/pow(256,1))));
		}
		temp=temp-(floor((temp/pow(256,1)))*pow(256,1));
		if(floor((temp/pow(256,0)))>0){
			em +=char(floor((temp/pow(256,0))));
		}
	}
	cout<<em<<endl;
}