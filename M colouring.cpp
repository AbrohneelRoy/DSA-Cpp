#include<iostream>
using namespace std;
const int s=4;
int graph[s][s],color[s];

bool safe(int n, int p){
    for(int i=0; i<s; i++){
        if(graph[p][i]==1 && n==color[i]){
            return false;
        }
    }
    return true;
}

bool malg(int m,int p){
    if(p==s){
        return true;
    }
    for(int i=1; i<=m; i++){
        if(safe(i,p)){
            color[p]=i;
            if(malg(m,p+1)){
                return true;
            }
            color[p]=0;
        }
    }
    return false;
}
int main(){
    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            cin>>graph[i][j];
        }
    }
    int m;
    cin>>m;
    for(int i=0; i<s; i++){
        color[i]=0;
    }
    if(malg(m,0)){
        for(int i=0; i<s; i++){
            cout<<color[i]<<" ";
        }
    }
    else{
        cout<<"No";
    }
}

// 0 1 1 1
// 1 0 1 0
// 1 1 0 1
// 1 0 1 0
// 3
