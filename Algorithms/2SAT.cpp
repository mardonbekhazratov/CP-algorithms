#include<bits/stdc++.h>
using namespace std;

struct _2SAT{
    int vars,vertices;
    vector<vector<int>>adj,adj_t;
    vector<bool>vis,assignment;
    vector<int>order,comp;
    _2SAT(int n) : vars(n), vertices(vars*2) {
        adj.resize(vertices);
        adj_t.resize(vertices);
        assignment.resize(vars);
    }

    void dfs1(int x){
        vis[x]=true;
        for(int z:adj[x]){
            if(!vis[z]){
                dfs1(z);
            }
        }
        order.push_back(x);
    }

    void dfs2(int x,int c){
        comp[x]=c;
        for(int z:adj_t[x]){
            if(comp[z]==-1){
                dfs2(z,c);
            }
        }
    }

    bool solve(){
        order.resize(0);
        vis.assign(vertices,false);
        for(int i=0;i<vertices;i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
        reverse(order.begin(),order.end());
        comp.assign(vertices,-1);
        int cs=0;
        for(int i:order){
            if(comp[i]==-1){
                dfs2(i,cs++);
            }
        }
        for(int i=0;i<vertices;i+=2){
            if(comp[i]==comp[i+1]) return false;
            assignment[i/2]=comp[i]>comp[i+1];
        }
        return true;
    }

    void add(int a,bool na,int b,bool nb){
        a=2*a^na;
        b=2*b^nb;
        int neg_a=a^1;
        int neg_b=b^1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};

signed main(){
    int n,m;
    cin>>n>>m;
    _2SAT S(m);
    for(int i=0;i<n;i++){
        char na,nb;
        int a,b;
        cin>>na>>a>>nb>>b;
        S.add(--a,na=='+',--b,nb=='+');
    }
    if(!S.solve()){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=0;i<m;i++){
        cout<<(S.assignment[i] ? '-' : '+')<<' ';
    }
}