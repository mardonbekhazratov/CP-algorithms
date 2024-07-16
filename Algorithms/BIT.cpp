#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

struct BIT{

    int n;
    vector<long long>bit;

    void init(int n){
        this->n=n;
        bit.assign(n,0);
    }

    BIT(vector<int>a){
        init((int)a.size());
        for(int i=0;i<a.size();i++){
            add(i,a[i]);
        }
    }

    void set(int id,int x){
        add(id,x-(get(id)-get(id-1)));
    }

    void add(int id,long long x){
        for( ; id<n; id=id|(id+1)){
            bit[id]=bit[id]+x;
        }
    }

    long long get(int id){
        long long ans=0;
        for(; id>=0; id=(id&(id+1))-1){
            ans=ans+bit[id];
        }
        return ans;
    }

    long long get(int l,int r){
        return get(r)-get(l-1);
    }
};

signed main(){
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    BIT S(a);
    while(q--){
        int id,l,r;
        cin>>id>>l>>r;
        if(id&1){
            S.set(l-1,r);
        }
        else{
            cout<<S.get(l-1,r-1)<<'\n';
        }
    }
}