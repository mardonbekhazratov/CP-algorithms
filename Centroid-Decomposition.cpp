//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>v;
vector<int>s;
int n;

int get_size(int x,int p=-1){
    int &res=s[x];
    res=1;
    for(int z:v[x]){
        if(z==p) continue;
        res+=get_size(z,x);
    }
    return res;
}

int get_centroid(int x,int p=-1){
    for(int z:v[x]){
        if(z==p) continue;
        if(s[z]*2>n) return get_centroid(z,x);
    }
    return x;
}

int main(){
    cin>>n;
    v.resize(n);
    s.assign(n,0);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;--a,--b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    get_size(0);
    cout<<get_centroid(0)+1;
}
