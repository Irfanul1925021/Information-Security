#include<bits/stdc++.h>
using namespace std;
#define dim 3
int keyMat[dim][dim];
int det(int i, int j, int type){
    int sub[4], ind = 0;
    for(int x=0;x<dim;x++){
        for(int y=0;y<dim;y++){
            if(i!=x&&j!=y){
                sub[ind++] = keyMat[x][y];
            }
        }
    }
    if(type==1)return keyMat[i][j]*(sub[0]*sub[3]-sub[1]*sub[2]);
    return (sub[0]*sub[3]-sub[1]*sub[2]);
}
void inverse_key_matrix(){

    int A = det(0,0,1)-det(0,1,1)+det(0,2,1);//determinant for i,j index of type 1
    (A%26<0)?A = A%26+26:A = A%26;

    //find multiplicative inverse of 1/A
    int i=1;
    while((A*i)%26!=1)i++;
    A = i;

    int adj[dim][dim];
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            if((i+j)%2==0)adj[i][j] = det(i,j,2);//determinant for i,j index of type 2
            else adj[i][j] = -det(i,j,2);
            (adj[i][j]%26<0)?adj[i][j] = adj[i][j]%26+26:adj[i][j] = adj[i][j]%26;
        }
    }

    swap(adj[1][0],adj[0][1]);
    swap(adj[2][0],adj[0][2]);
    swap(adj[1][2],adj[2][1]);

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            keyMat[i][j] = (adj[i][j]*A)%26;
        }
    }

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif

    //-->input
    string pt; getline(cin,pt); pt.erase(remove(pt.begin(), pt.end(), ' '), pt.end());
    string key; getline(cin,key); key.erase(remove(key.begin(), key.end(), ' '), key.end());

    //--> make key matrix
    int ind = 0;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            keyMat[i][j] = (key[ind++]-'a');
        }
    }

    inverse_key_matrix();//uncomment this function for decryption part
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
            if(state[j]<0)state[j]+=26;

        }

        for(int j=0;j<dim;j++)cipher_text+=(state[j]+'a');
    }
    cout << cipher_text << endl;

}
