#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll M=1e9+7;
const ll x=993146723;

struct Hash{
    int n;
    vector<ll>h,p;

    Hash(string&s){
        n=s.size();
        h.resize(n+1,0);
        p.resize(n+1,1);
        for(int i=1;i<=n;i++){
            h[i]=(h[i-1]*x+s[i-1])%M;
            p[i]=(p[i-1]*x)%M;
        }
    }

    int get(int l,int r){
        return (h[r]-h[l-1]*p[r-l+1]%M+M)%M;
    }

    int get(){
        return h[n];
    }
};

void solve(){
    string s,t;
    cin>>s>>t;
    Hash S(s);
    Hash T(t);
    int ans=0;
    for(int i=t.size();i<=s.size();i++){
        if(S.get(i-t.size()+1,i)==T.get()) ans++;
    }
    cout<<ans;
}

signed main(){
    int t=1;
    #ifdef TESTCASES
        cin>>t;
    #endif
    while(t--){
        solve();
        cout<<'\n';
    }
}