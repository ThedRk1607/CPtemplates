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
#define RS set <ll, greater <ll> >
#define PQS priority_queue<ll,vector<ll>,greater<ll>> 
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

vl dp;
vb used;
vector<vector<ll>>g;

ll dfs(ll v){
	if(used[v])return dp[v];
	used[v]=true;
	ll s=0;
	for(auto u:g[v]){
		s+=dfs(u);
	}
	if(!g[v].empty())dp[v]=min(dp[v],s);
	return dp[v];
}

void solve(){
	int n,k;cin>>n>>k;
	dp.resize(n);
	used.assign(n,false);
	g.assign(n,vector<ll>(0));
	FORR(x,dp)cin>>x;
	for(int i=0;i<k;i++){
		int e;cin>>e;
		e--;
		dp[e]=0;
	}
	for(int i=0;i<n;i++){
		int m;cin>>m;
		g[i].resize(m);
		FORR(x,g[i])cin>>x,x--;
	}

	for(int i=0;i<n;i++)dfs(i);

		FORR(x,dp)cout<<x<<" ";
	cout<<nl;


	
}

int32_t main()
{
 
	#ifndef ONLINE_JUDGE
 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 #endif
   
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

   int T=1;cin >> T;
   while(T--)solve();
  
	#ifdef DEBUG
		cerr << "Runtine is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
    
    return 0;
    
    }
