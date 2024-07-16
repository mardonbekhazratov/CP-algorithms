#include<bits/stdc++.h>
using namespace std;

const int N=5002;

vector<vector<int>>g;
vector<int>mt;
vector<bool>used;

bool try_kuhn(int x){
    if(used[x])
        return false;
    used[x]=true;
    for(int to:g[x]){
        if(mt[to]==-1 || try_kuhn(mt[to])){
            mt[to]=x;
            return true;
        }
    }
    return false;
}

signed main(){
    int n,m;
    cin>>n>>m;
    vector<int>p(n+1),c(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    int q;
    cin>>q;
    vector<int>queries(q);
    vector<bool>deleted(n+1,false);
    for(int &x:queries){
        cin>>x;
        deleted[x]=true;
    }
    reverse(queries.begin(),queries.end());

    g.assign(N,{});
    for(int i=1;i<=n;i++){
        if(!deleted[i]){
            g[p[i]].push_back(c[i]);
        }
    }
    
    mt.assign(N,-1);
    used.assign(N,false);
    int now=0;
    while(try_kuhn(now)){
        now++;
        used.assign(N,false);
    }

    vector<int>ans;
    for(int &x:queries){
        used.assign(N,false);
        while(try_kuhn(now)){
            now++;
            used.assign(N,false);
        }
        ans.push_back(now);
        g[p[x]].push_back(c[x]);
    }
    
    reverse(ans.begin(),ans.end());
    for(int &x:ans) cout<<x<<'\n';
}