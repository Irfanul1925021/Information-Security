#include<iostream> //Caesar Cipher Implementation
#include<cstring>
using namespace std;
int main(){
// ...
string x ;
cin>>x;
char *y = new char[x.length() + 1];

std::strcpy(y, x.c_str());
cout<<"Encrypted code:";
cout<<y;
for(int i=0;i<x.length()+1;i++)
{
	 y[i]=char(int(y[i])+3); //Variations are applicable
}
    cout<<endl;
    cout<<"Cipher code to decrypt:";
for(int j=0;j<x.length()+1;j++){

cout<<y[j];
}
cout<<endl;
cout<<"Decrypted code:";
for(int k=0;k<x.length()+1;k++){
cout<<char(int(y[k]-3));
}
	return 0;
}
