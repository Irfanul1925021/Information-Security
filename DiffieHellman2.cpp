//Qc
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


ll Alice(ll g, ll n){
    x = 3;
    return pw(g,x,n);
}

ll Bob(ll g, ll n){
    y = 6;
    return pw(g,y,n);
}

ll getKeyFromAlice(ll B, ll x, ll n){
    return pw(B,x,n);
}

ll getKeyFromBob(ll A, ll y, ll n){
    return pw(A,y,n);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif

	// take 2 big prime
    ll g = 7, n = 11; //cin >> g >> n;

    A = Alice(g,n);

    B = Bob(g,n);

    ll k1 = getKeyFromAlice(B,x,n);
    ll k2 = getKeyFromBob(A,y,n);

    cout << k1 << " " << k2 << endl;

}

