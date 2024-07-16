#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int>length,parent;
    DSU(int x){
        n=x;
        parent.resize(n+1);
        length.resize(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        for(int i=1;i<=n;i++) length[i]=1;
    }

    int find(int x){
        if(x==parent[x]) return x;
        return x=find(parent[x]);
    }

    bool same(int a,int b){
        return (find(a)==find(b));
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(length[a]<length[b]) swap(a,b);
        length[a]+=length[b];
        parent[b]=a;
    }
};

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    DSU UF(n);
    int cnt=n,mx=1;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(!UF.same(x,y)){
            cnt--;
            UF.unite(x,y);
        }
        mx=max(mx,UF.length[UF.find(x)]);
        cout<<cnt<<' '<<mx<<'\n';
    }
}