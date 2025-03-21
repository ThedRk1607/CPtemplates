#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int solve(vector <int> &c, int bit){
    if(bit < 0) return 0;
    vector <int> l, r;
    for(auto &i : c){
        if(((i >> bit) & 1) == 0) l.push_back(i);
        else r.push_back(i);
    }
    if(l.size() == 0) return solve(r, bit - 1);
    if(r.size() == 0) return solve(l, bit - 1);
    return min(solve(l, bit - 1), solve(r, bit - 1)) + (1 << bit);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    cout << solve(a, 30) << endl;
}
//trie solution use dnc remember when use some x factor;

struct trie{
	trie*child[2];int cnt;bool stop=false;
	trie(){
		rep(i,0,2)child[i]=NULL;cnt=0;
	}
};
 
void insert(int n,trie*root){
	trie*node=root;
  for(int b=30;b>=0;b--){
  	int x=(n>>b&1);
  	if(node->child[x]==NULL){
  		node->child[x]=new trie();
  	}
  	node=node->child[x];
  	node->cnt++;
  }
	node->stop=true;
}
 
int q(trie*root,int x){
		if(x == -1 or root == nullptr)return 0;
 
	int L = q(root->child[0], x-1);
	int R = q(root->child[1], x-1);
	bool hasleft = root->child[0] != nullptr;
	bool hasright = root->child[1] != nullptr;
	return (hasleft and hasright ? (1LL << x) + min(L, R) : L + R);
 
	
}
 
 
 
 
void solve(){
	int n;cin>>n;
	trie*T=new trie();
	rep(i,0,n){int x;cin>>x;insert(x,T);}
	cout<<q(T,30);
 
 
	
}
