#include<bits/stdc++.h>
using namespace std;

struct KMP{
    vector<int>p;
    int n;
    KMP(string &s){
        n=s.size();
        p.resize(n);
        for(int i=1;i<n;i++){
            int j=p[i-1];
            while(j>0 && s[i]!=s[j])
                j=p[j-1];
            if(s[i]==s[j]) j++;
            p[i]=j;
        }
    }
};

signed main(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    s=t+"#"+s;
    KMP P(s);
    int ans=0;
    for(int i=1;i<=n+m;i++){
        if(P.p[i]==m) ans++;
    }
    cout<<ans;
}