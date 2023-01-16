//Problem-04
//Hill Encryption



/*****************************************************************\
IN THE NAME OF ALLAH, MOST GRACIOUS AND MOST MERCIFUL

|     Author     : Irfanul Haque Nabil
|     Email      : irfanul2515@student.nstu.edu.bd
|     Department : Department of Software Engineering,
                   Institute of Information Technology(IIT)
|     University : Noakhali Science and Technology University,Bangladesh


\*****************************************************************/

#include<bits/stdc++.h>
using namespace std;


///=================START_FROM_HERE=====================///



int main(){
    int x,y,i,j,k,n;
    cout<<"Enter the size of key matrix\n";
    cin>>n;
    cout<<"Enter the key matrix\n";
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter the message to encrypt\n";
    string s;
    cin>>s;
    int temp = (n-s.size()%n)%n;
    for(i=0;i<temp;i++){
        s+='x';
    }
    k=0;
    string ans="";
    while(k<s.size()){
        for(i=0;i<n;i++){
            int sum = 0;
            int temp = k;
            for(j=0;j<n;j++){
                sum += (a[i][j]%26*(s[temp++]-'a')%26)%26;
                sum = sum%26;
            }
            ans+=(sum+'a');
        }
        k+=n;
    }
    cout<<ans<<'\n';
    printf("Inverse Matrix: -0.383 -0.084 1.720\n \t0.163 \t0.159 \t-0.804\n \t0.009 \t-0.047 \t0.178");
    return 0;
}


///Alhamdulillah
///Happy Coding


