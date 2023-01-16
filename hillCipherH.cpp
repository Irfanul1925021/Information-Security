#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif

    //-->input
    string pt; getline(cin,pt); pt.erase(remove(pt.begin(), pt.end(), ' '), pt.end());
    string key; getline(cin,key); key.erase(remove(key.begin(), key.end(), ' '), key.end());

    //--> make key matrix
    int keyMat[5][5], ind = 0, dim = 3;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            keyMat[i][j] = (key[ind++]-'a');
        }
    }
    //--> encrypt part
    string cipher_text = "";
    for(int i=0;i<pt.size();i+=dim){
        int p[dim], state[dim];
        for(int j=i,lmt = 0;lmt<dim;lmt++,j++){
            p[j-i] = (pt[j]-'a');
        }
        for(int j=0;j<dim;j++){
            int sum = p[0]*keyMat[0][j]+p[1]*keyMat[1][j]+p[2]*keyMat[2][j];
            state[j] = sum%26;
        }

        for(int j=0;j<dim;j++)cipher_text+=(state[j]+'a');
    }
    cout << cipher_text << endl;

}
