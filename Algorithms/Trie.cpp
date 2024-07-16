#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>trie;
vector<bool>is_word;

void insert(string s){
    if(trie.size()==0){
        trie.push_back(vector<int>(26,0));
        is_word.push_back(false);
    }
    int node=0;
    for(char c:s){
        if(trie[node][c-'a']==0){
            trie[node][c-'a']=(int)trie.size();
            trie.push_back(vector<int>(26,0));
            is_word.push_back(false);
        }
        node=trie[node][c-'a'];
    }
    is_word[node]=true;
}

signed main(){
    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(a[i]);
    }
}