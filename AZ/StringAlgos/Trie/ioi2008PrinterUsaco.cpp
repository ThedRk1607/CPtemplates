#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b)for(int i=a;i<b;i++)
#define repp(x,arr) for(auto& x:arr)

#define ll              long long
#define ull              unsigned long long 
#define int ll
#define db              double
#define pb              push_back
#define all(v)             v.begin(),v.end()
#define F               first
#define S               second
#define mod              1000000007
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define nl              "\n"
#define PI              3.1415926536 //acos(-1.0)
#define eps 0.00000001
#define mpp                 make_pair
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue<int> //by default provide largest element;
#define RS set <ll, greater <ll> >
#define PQS priority_queue<ll,vector<ll>,greater<ll>> 
#define ZERO(a) memset(a,0,sizeof(a))
#define inf 0x3f3f3f3f


using vi = vector<int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const int dxn[8]={0,1,1,1,0,-1,-1,-1},dyn[8]={1,1,0,-1,-1,-1,0,1};
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }
template <typename A, typename B> A mod1 (A &a, B b){ a=(a%b+b)%b ; return a; }


int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isleap(int by){return (by%4==0 && (by%100!=0 || by%400==0));};
inline int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);}


inline int mul(int a, int b) { return (int) ((long long) (a%mod * b%mod) % mod);}
inline int add(int a,int b){return (a%mod+b%mod)%mod;}
inline int sub(int a,int b){return (a-b+mod)%mod;}
inline int binpow(int a,int b){
	a%=mod;int res=1;
while(b){if(b&1)res=res*a%mod;a=a*a%mod;b/=2;}
return res;
}

inline int inv(int a){return binpow(a,mod-2)%mod;}

struct trie{
	trie*child[26];int cnt=0;bool stop=false;
	trie(){
		rep(i,0,26)child[i]=NULL;
		//cnt=0;
	}
};

void insert(const string&s,trie*root){
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
}


map<trie*,int>d;
void dfs(trie*node){
	d[node]=1;
	for(int i=0;i<26;i++){
		if(!node->child[i])continue;
		dfs(node->child[i]);
		d[node]=max(d[node],d[node->child[i]]+1);
	}
}

string t;
void dfs2(trie*node){
	if(node->stop==true)t+='P';
	for(int i=0;i<26;i++){
		if(!node->child[i])continue;
		if(d[node]>d[node->child[i]]+1){
			t+=(char)(i+'a');
			dfs2(node->child[i]);
		}
	}
	for(int i=0;i<26;i++){
		if(!node->child[i])continue;
		if(d[node]==d[node->child[i]]+1){
			t+=(char)(i+'a');
			dfs2(node->child[i]);
		}
	}
	
	t+='-';
}
//https://ioinformatics.org/files/ioi2008solutions.pdf //sol link editorial

void solve(){
  int n;cin>>n;
  trie*a=new trie();
  rep(i,0,n){string s;cin>>s;insert(s,a);}
  dfs(a);
  dfs2(a);

 
  while(t.back()=='-')t.pop_back();
  cout<<t.size()<<nl;
  repp(x,t)cout<<x<<nl;

  

}



	



int32_t main()
{
 	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif


   
   ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);


 
  
   int T=1;//cin >> T;
   while(T--)solve();
  


    return 0;
    
    }
