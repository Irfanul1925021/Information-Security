#include<bits/stdc++.h>
using namespace std;
#define pc(x) cout<<"Case "<<x<<": "
#define rep(y,x) for(int y=0;y<x;y++)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ll long long
#define pll pair<ll,ll>
#define inf 1000000009
int cse = 1;
vector<int>isPrime(100002,0);
bitset<1000000>bt;

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; getline(cin,s);
    cout << s << endl; int k = 3;
    for(int i=0;i<s.size();i++){
        s[i] = (((s[i]-'a')+k)%26+'a');
    }
    cout << s << endl;
    for(int i=0;i<s.size();i++){
        if(s[i]-'a'-k<0)s[i] = (((s[i]-'a')-k)%26+26+'a');
        else s[i] = (((s[i]-'a')-k)%26+'a');
    }
    cout << s << endl;
}

