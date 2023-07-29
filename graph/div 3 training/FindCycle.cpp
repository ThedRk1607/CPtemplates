
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)for(int i=a;i<b;i++)
#define FORR(x,arr) for(auto& x:arr)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ll              long long
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
#define PQS priority_queue<ll,vector<ll>,greater<ll>> 
#define RS set<int, greater<int> >
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0x3f,sizeof(a))
#define ll28    __int128
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const int dxn[8]={1,0,-1,0,-1,1,-1,1},dyn[8]={0,1,0,-1,-1,1,1,-1};
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }
const int N=2<<17;
int n,m;
vector<int>adj[N];
int color[N];
vi par(N,-1),cycle;

bool dfs(int node){
	color[node]=1;

	for(auto v:adj[node]){
		if(color[v]==0){
			par[v]=node;
			if(dfs(v))return true;
		}else {
			int cur=node;
			while(cur!=v){
				cycle.pb(cur);
				cur=par[cur];
			}
			cycle.pb(v);
			//cycle.pb(node);
			return true;

		}
	}
	color[node]=2;
	return false;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
	}
	
ZERO(color);
for(int i=1;i<=n;i++){
	if(color[i]==0){
		if(dfs(i)){
			cout<<"YES\n";
			FORR(x,cycle)cout<<x<<" "; 
			cout<<nl;
			return;
		}
	}
}

	cout<<"NO\n";
	

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
