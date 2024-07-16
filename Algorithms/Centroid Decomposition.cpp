#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>v;
vector<int>ans,subtree;
vector<bool>removed;

int get_size(int x,int p){
    subtree[x]=1;
    for(int z:v[x]){
        if(z!=p && !removed[z]) subtree[x]+=get_size(z,x);
    }
    return subtree[x];
}

int get_centroid(int x,int p,int d){
    for(int z:v[x]){
        if(z==p || removed[z]) continue;
        if(subtree[z]>d) return get_centroid(z,x,d);
    }
    return x;
}

void build(int x,int c){
    int N=get_size(x,x);
    int centroid=get_centroid(x,x,N/2);
    ans[centroid]=c;
    removed[centroid]=1;
    for(int z:v[centroid]){
        if(!removed[z]){
            build(z,c+1);
        }
    }
}

signed main(){
    int n;
    cin>>n;
    v.resize(n+1);
    ans.resize(n+1);
    removed.assign(n+1,0);
    subtree.resize(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    build(1,0);
    for(int i=1;i<=n;i++){
        cout<<char(ans[i]+'A')<<" ";
    }
}