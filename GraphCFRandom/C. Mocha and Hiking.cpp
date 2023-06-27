

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for(int i = a; i < int(n);i++ )
#define FORR(x,arr) for(auto& x:arr)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ll               long long 
#define ull              unsigned long long 
#define db 				double
#define pb              push_back
#define all(v)             v.begin(),v.end()
#define F               first
#define S               second
#define INF             1000000007
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define nl  			"\n"
#define PI   			3.1415926536
#define eps 0.00000001
#define mpp 				make_pair
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue
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
 const int mod=1e9+7;


int n;
vector<int>adj[10005];
bool vis[10005];
vector<int>path;

// void dfs(int u){
// 	vis[u]=true;
// 	comp.pb(u);
// 	for(auto v:adj[u]){
// 		if(vis[v])continue;
// 		dfs(v);
// 		//vis[v]=false;

// 	}
	
// }


bool dfs(int node) {
    vis[node] = true;
    path.push_back(node);

    if (path.size() == n+1) {
        return true;  // All villages vis
    }

    for (int neighbor : adj[node]) {
        if (!vis[neighbor] && dfs(neighbor)) {
            return true;
        }
    }

    vis[node] = false;
    path.pop_back();
    return false;
}

 void solve(){
 	cin>>n;
 	vi v(n);
 	FORR(x,v)cin>>x;
 	for(int i=1;i<=n-1;i++){
 		  adj[i].pb(i+1);
 	}

 	for(int i=0;i<n;i++){
 		if(v[i]==0)adj[i+1].pb(n+1);
 		else adj[n+1].pb(i+1);
 	}

 
//  	bool ok=false;
//  	for(int i=n+1;i>=1;i--){
//  			ZERO(vis);
//  			comp.clear();
//  			dfs(i);
//  			if(comp.size()==n+1){
//  				ok=true;
//  				break;
//  			}

//  	}
// if(!ok){
// 	cout<<"-1\n";
// 	return;
// }

// for(int i=0;i<=n;i++)cout<<comp[i]<<" ";
// cout<<nl;



for(int i=1;i<=n+1;i++){
	ZERO(vis);
	path.clear();
	if(dfs(i)){
		FORR(x,path)cout<<x<<" ";
		cout<<nl;
		return;
	}


}
cout<<"-1\n";
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
