#include<bits/stdc++.h>

using namespace std ;

#define ll long long

int A , x ;
int B , y ;


ll pw(ll b , ll p , ll mod){

    ll k ;
    if(p==0) return 1 ;

    if(p % 2) return (b * pw(b , p-1 , mod)) % mod ;
    else{
        k = pw(b , p/2 , mod) ;
        return (k*k)%mod ;
    }
}


int main(){

    ll g = 7 , n = 11 ;

    x = 3; // x is private to Alice

    A = pw(g  , x , n) ;

    y = 6 ;
    B = pw(g , y,n) ;

    ll k1 = pw(B , x , n) ;
    ll k2 = pw(A , y  ,n) ;

    cout << k1 << " " << k2 << endl;

}
