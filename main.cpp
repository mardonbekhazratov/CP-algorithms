/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define ll long long
// #define int ll
#define ff first
#define ss second
#define pi pair<int,int>
#define vi vector<int>
#define mi map<int,int>
#define mll map<ll,ll>
#define vll vector<ll>
#define vvi vector<vi>
#define vpi vector<pi>
#define pb push_back
#define p_b pop_back
#define all(x) (x).begin(),(x).end()
#define print(a,l,r) for(int qwert=l;qwert<r;qwert++)cout<<a[qwert]<<' '
#define input(a,l,r) for(int qwert=l;qwert<r;qwert++)cin>>a[qwert]

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


const int M=1e9+7;
const int MOD=998244353;
//const int N=1e6;
const int INF=1e9;
const ll INFLL=1e18;

/*
#define LOCAL
#define TESTCASES
*/


void solve(){
    ;
}

signed main(){

    //cin.tie(0)->sync_with_stdio(0);

    auto start = chrono::high_resolution_clock::now();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    
    int t=1;
    

    #ifdef TESTCASES
        cin>>t;
    #endif

    for(int tests=0;tests<t;tests++){
        solve();
        //cout<<(solve()?"YES":"NO");
        cout<<'\n';
    }

    #ifdef LOCAL
        auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start);
	
	    cerr << "time: " << (double)duration.count()/1000.0 << " milliseconds" << endl;
    #endif

    return 0;
}
