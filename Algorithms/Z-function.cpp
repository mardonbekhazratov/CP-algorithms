#include<bits/stdc++.h>
using namespace std;

struct ZF{
    vector<int>z;
    ZF(string &s){
        z.assign(s.size(),0);
        int l=0;
        for(int i=1;i<s.size();i++){
            z[i]=max(0,min(z[i-l],l+z[l]-i));
            while(i+z[i]<s.size()&&s[i+z[i]]==s[z[i]])
                z[i]++;
            if(z[i]+i>l+z[l]) l=i;
        }
    }
};


signed main(){
    string s;
    cin>>s;
    int n=s.size();
    ZF Z(s);
    for(int i=1;i<=n;i++){
        int cur=i;
        while(cur<n&&Z.z[cur]>=min(i,n-cur)) cur+=i;
        if(cur>=n) cout<<i<<' ';
    }
}