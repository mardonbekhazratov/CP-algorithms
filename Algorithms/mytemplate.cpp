// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

// #include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <typeinfo>
#include <chrono>

#include <vector>
#include <map>
#include <array>
#include <set>
#include <queue>
#include <stack>
#include <deque>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>
#include <climits>

using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>

// using namespace __gnu_pbds;
// template<typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>void print(vector<T>a,int l,int r){for(int i=l;i<r;i++)cout<<a[i]<<' ';}
template<typename T>void print(vector<T> a){for(T x:a)cout<<x<<' ';}
template<typename T>void input(vector<T>a,int l,int r){for(int i=l;i<r;i++)cin>>a[i];}
template<typename T>void input(vector<T>&a){for(T&x:a)cin>>x;}

#define ll long long
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pb push_back
#define p_b pop_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int M=1e9+7;
const int MOD=998244353;
const int INF=1e9;
const ll INFLL=2e18;

// #define LOCAL
#define TESTCASES

// #define int ll



void solve( const int &test_case ){
    ;
}

signed main(){

    cin.tie(0)->sync_with_stdio(0);cout.tie(0);
    
    #ifdef LOCAL
        auto start = chrono::high_resolution_clock::now();
        
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    
    int TESTS=1;
 
    #ifdef TESTCASES
        cin>>TESTS;
    #endif
 
    for(int test_case=0;test_case<TESTS;test_case++){
        solve(test_case);
        cout<<'\n';
    }
 
    #ifdef LOCAL
        auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start);
	
	    cerr << "time: " << (double)duration.count()/1000.0 << " milliseconds" << endl;
    #endif
 
    return 0;
}