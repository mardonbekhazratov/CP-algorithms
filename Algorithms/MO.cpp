#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN=1e6;
vector<ll>fr(2*mxN+5,0);

int BLOCK_SIZE;

bool cmp(auto a,auto b){
    return make_pair(a[0]/BLOCK_SIZE,a[1])<make_pair(b[0]/BLOCK_SIZE,b[1]);
}

vector<ll>MO(vector<array<int,3>>Q,vector<int>a){
    BLOCK_SIZE=sqrt((int)a.size());
    vector<ll>ans(Q.size());
    sort(Q.begin(),Q.end(),cmp);
    int cur_l=1,cur_r=0;
    ll s=0;
    for(array<int,3>q:Q){
        while(cur_l>q[1]){
            cur_l--;
            s-=fr[a[cur_l]+mxN]*(fr[a[cur_l]+mxN]+a[cur_l]);
            fr[a[cur_l]+mxN]++;
            s+=fr[a[cur_l]+mxN]*(fr[a[cur_l]+mxN]+a[cur_l]);
        }
        while(cur_r<q[0]){
            cur_r++;
            s-=fr[a[cur_r]+mxN]*(fr[a[cur_r]+mxN]+a[cur_r]);
            fr[a[cur_r]+mxN]++;
            s+=fr[a[cur_r]+mxN]*(fr[a[cur_r]+mxN]+a[cur_r]);
        }
        while(cur_r>q[0]){
            s-=fr[a[cur_r]+mxN]*(fr[a[cur_r]+mxN]+a[cur_r]);
            fr[a[cur_r]+mxN]--;
            s+=fr[a[cur_r]+mxN]*(fr[a[cur_r]+mxN]+a[cur_r]);
            cur_r--;
        }
        while(cur_l<q[1]){
            s-=fr[a[cur_l]+mxN]*(fr[a[cur_l]+mxN]+a[cur_l]);
            fr[a[cur_l]+mxN]--;
            s+=fr[a[cur_l]+mxN]*(fr[a[cur_l]+mxN]+a[cur_l]);
            cur_l++;
        }
        ans[q[2]]=s;
    }
    return ans;
}

signed main(){
    int n,q;
    cin>>n>>q;
    vector<int>a(n+1);
    vector<array<int,3>>Q(q);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<q;i++){
        cin>>Q[i][1]>>Q[i][0];
        Q[i][2]=i;
    }
    vector<ll>ans=MO(Q,a);
    for(ll z:ans) cout<<z<<'\n';
}