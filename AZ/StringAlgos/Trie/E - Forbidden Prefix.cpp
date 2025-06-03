//link-https://atcoder.jp/contests/abc403/tasks/abc403_e
//ABC403
// other trie solution
//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 500010
using namespace std;
int q,op[N],idx[N],ch[N][26],num[N],tot=1,ans=0;
bool vis[N];
string s[N];
void dfs(int x){
	vis[x]=true;
	ans-=num[x];
	num[x]=0;
	for(int i=0;i<26;i++) if(ch[x][i]&&(!vis[ch[x][i]])) dfs(ch[x][i]);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>op[i]>>s[i];
		int x=1;
		for(int j=0;j<s[i].size();j++){
			if(!ch[x][s[i][j]-'a']) ch[x][s[i][j]-'a']=++tot;
			x=ch[x][s[i][j]-'a'];
		}
		idx[i]=x;
	}
	for(int i=0;i<q;i++){
		if(op[i]==1){
			if(!vis[idx[i]]) dfs(idx[i]);
		}
		else{
			if(!vis[idx[i]]) num[idx[i]]++,ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}


//mine trie solution
const int N=2e5+5;
const double EPS = 1.0*(N-1)/N;
#define UP(x) (x + EPS)


struct trie{
	trie*child[26];int cnt=0;bool stop=0;
	trie(){
		rep(i,0,26)child[i]=NULL;
	}
};

trie*idx[N];
int op[N];string s[N];
map<trie*,int>vis,num;
int ans;

void dfs(trie*node){
  vis[node]=1;
  ans-=num[node];
	for(int i=0;i<26;i++){
		if(!node->child[i] or vis[node->child[i]])continue;
		dfs(node->child[i]);
	}
}

void insert(trie*root,string &s,int i){
	trie*node=root;
	for(auto ch:s){
		int id=(ch-'a');
		if(!node->child[id]){
			node->child[id]=new trie();
		}
		node=node->child[id];
		node->cnt++;
	}
	node->stop=true;
	idx[i]=node;
}

void solve(){
	int q;cin>>q;
	trie*T=new trie();
	rep(i,0,q){
		cin>>op[i]>>s[i];
		insert(T,s[i],i);
	}
	rep(i,0,q){
		if(op[i]==1){
			if(!vis[idx[i]])dfs(idx[i]);
		}else{
			if(!vis[idx[i]]){ans++;num[idx[i]]++;}
		}
		cout<<ans<<nl;
	}

}
