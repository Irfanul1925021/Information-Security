#include<bits/stdc++.h>
using namespace std;

#define ll long long

int A,x;//for Alice
int B,y; //for Bob

ll pw(ll b, ll p, ll mod)
{
    ll k;
    if(p==0)return 1;
    if(p%2)return (b*pw(b,p-1,mod))%mod;
    else { k=pw(b,p/2,mod); return (k*k)%mod;}
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
	// Assume two person Alice and Bob
    ll g = 7, n = 11;

    x = 3;//x is private to Alice
    A = pw(g,x,n);;

    y = 6;//y is private to Bob
    B = pw(g,y,n);

    ll k1 = pw(B,x,n);// k1 is for Alice
    ll k2 = pw(A,y,n);// k2 is for Bob

    cout << k1 << " " << k2 << endl;
}

