
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
#define triple  tuple<int,int,string>;
#define printTuple get<i>(name)

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vpi = vector<pii>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const int dxn[8]={1,0,-1,0,-1,1,-1,1},dyn[8]={0,1,0,-1,-1,1,1,-1};
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

ll dp[1001][10];

void solve(){
	int n;cin>>n;
	vpi v(n+1);
	FOR(i,1,n+1){
		int x;string s;cin>>x>>s;
		int mask=0;
		FORR(j,s){
			if(j=='A')mask+=(1<<2);
			if(j=='B')mask+=(1<<1);
			if(j=='C')mask+=(1<<0);
		}
		v[i]={x,mask};

	}

for(int i=0;i<1001;i++)
	for(int j=0;j<10;j++)dp[i][j]=INF;

   dp[0][0]=0;

	for(int i=1;i<=n;i++){
		for(int j=0;j<8;j++){
			dp[i][j]=min(dp[i][j],dp[i-1][j]);
			dp[i][j|v[i].S]=min(dp[i-1][j]+v[i].F,dp[i][j|v[i].S]);
		}
	}
ll ans=dp[n][7];
if(ans==INF)ans=-1;



cout<<ans;

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
