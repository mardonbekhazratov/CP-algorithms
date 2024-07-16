#include<bits/stdc++.h>
using namespace std;

struct LCA{

    int n,q,timer;
    const int l=20;
    vector<vector<int>>v,up;
    vector<int>tin,tout,depth;

    LCA(int N,vector<vector<int>>V):n(N),v(V){
        timer=0;
        tin.resize(n+1);
        tout.resize(n+1);
        depth.resize(n+1);
        up.assign(n+1,vector<int>(l,0));
        dfs(1,1,0);
        for(int i=1;i<l;i++){
            for(int j=1;j<=n;j++){
                up[j][i]=up[up[j][i-1]][i-1];
            }
        }
    }

    void dfs(int x,int p,int c){
        tin[x]=++timer;
        depth[x]=c;
        up[x][0]=p;
        for(int z:v[x]){
            if(z!=p) dfs(z,x,c+1);
        }
        tout[x]=++timer;
    }

    bool is_ancestor(int x,int y){
        return tin[x]<=tin[y] && tout[y]<=tout[x];
    }

    int lca(int x,int y){
        if(is_ancestor(x,y)) return x;
        if(is_ancestor(y,x)) return y;

        for(int i=l-1;i>=0;i--){
            if(!is_ancestor(up[x][i],y)){
                x=up[x][i];
            }
        }
        return up[x][0];
    }

};

vector<vector<int>>v;

signed main(){
    int n;
    cin>>n;
    v.resize(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    LCA l(n,v);
}