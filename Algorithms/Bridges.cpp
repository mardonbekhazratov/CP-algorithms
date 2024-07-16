#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<bool>vis;
vector<int>tin,low;
vector<pair<int,int>>bridges;
int timer;

void dfs(int v,int p=-1){
    vis[v]=true;
    tin[v]=low[v]=timer++;
    for(int to:g[v]){
        if(to==p) continue;
        if(vis[to]){
            low[v]=min(low[v],tin[to]);
        }
        else{
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>tin[v]){
                bridges.push_back({v,to});
            }
        }
    }
}

void find_bridges(int n){
    timer=0;
    vis.assign(n+1,false);
    tin.assign(n+1,-1);
    low.assign(n+1,-1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout<<bridges.size()<<'\n';
    for(auto [x,y]:bridges){
        cout<<x<<' '<<y<<'\n';
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.assign(n+1,{});
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    find_bridges(n);
}

signed main(){
    int T=1;
    // cin>>T;
    while(T--){
        solve();
        cout<<'\n';
    }
}