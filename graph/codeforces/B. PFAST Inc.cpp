
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)for(int i=a;i<b;i++)
#define FORR(x,arr) for(auto& x:arr)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ll               long long 
#define ull              unsigned long long 
#define db              double
#define pb              push_back
#define all(v)             v.begin(),v.end()
#define F               first
#define S               second
#define INF             1000000007
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define nl              "\n"
#define PI              3.1415926536
#define eps 0.00000001
#define mpp                 make_pair
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue //by default provide largest element;
#define PQS priority_queue<int,vector<int>,greater<int>> 
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0x3f,sizeof(a))

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const int dxn[8]={1,0,-1,0,-1,1,-1,1},dyn[8]={0,1,0,-1,-1,1,1,-1};
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const int N=100;
vector<int>adj[N];
bool vis[N];
int n,m;
bool g[100][100];

// void dfs(int u){
// 	vis[u]=true;
	
// 	for(auto v:adj[u]){
// 		if(vis[v])continue;
// 		dfs(v);
// 	}
// }

void solve(){
	cin>>n>>m;
	map<string,int>mp;
	vs st(n+1);
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		st[i]=s;
		mp[s]=i;

	}
bool flag;
	for(int i=0;i<m;i++){
		string s,t;cin>>s>>t;
		g[mp[s]][mp[t]]=true;
		g[mp[t]][mp[s]]=true;

	}

	vs ans;
	for(int i=0;i<(1<<n);i++){
		vs check;
		for(int j=0;j<n;j++){
			if(i&(1<<j))check.pb(st[j+1]);
		}
		flag=true;
		for(int j=0;j<check.size() and flag;j++){
			for(int k=j+1;k<check.size();k++){
				if(g[mp[check[j]]][mp[check[k]]]){
					flag=false;
					break;
				}
			}
		}
		if(flag and check.size()>ans.size())ans=check;
	}

	sort(all(ans));
	cout<<ans.size()<<nl;
	FORR(x,ans)cout<<x<<nl;

	

}

int32_t main()
{
 
	#ifndef ONLINE_JUDGE
 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 #endif
   
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
   int T=1;//cin >> T;
   while(T--)solve();
  
	#ifdef DEBUG
		cerr << "Runtine is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
    
    return 0;
    
    }
