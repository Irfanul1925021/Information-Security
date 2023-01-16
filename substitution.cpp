#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int k;
    cout<<"Enter the value of k = ";
    cin>>k;
    for(int i=0; i<s.size(); i++)
    {
          if(s[i]==' '){
          continue;
          }
        s[i] = (((s[i]-'a')+k)%26+'a');
    }
    cout<<"Encrypted message : ";
    cout << s << endl;
    for(int i=0; i<s.size(); i++)
    {
          if(s[i]==' '){
          continue;
          }
        if(s[i]-'a'-k<0){
            s[i] = (((s[i]-'a')-k+26)%26+'a');
        }
        else{
            s[i] = (((s[i]-'a')-k)%26+'a');
        }
    }
    cout<<"Decrypt message : ";
    cout << s << endl;
}
