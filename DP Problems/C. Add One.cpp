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
#define PQ priority_queue<pii> //by default provide largest element;
#define RS set <ll, greater <ll> >
#define PQS priority_queue<pll,vector<pll>,greater<pll>> 
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

const int mod=1e9+7,N=2e5+5;

int dp[N];

void prec(){
	for(int i=0;i<9;i++)dp[i]=2;
	dp[9]=3;
	
	for(int i=10;i<N;i++){
		dp[i]=(dp[i-9]+dp[i-10])%mod;
	}
}

void solve(){
	int n,m;cin>>n>>m;
	int ans=0;
	while(n){
		int x=n%10;
		ans+=((m+x<10)?1:dp[m+x-10]);
		ans%=mod;
		n/=10;
	}

	cout<<ans<<nl;
	
	

}


int32_t main()
{
 
	#ifndef ONLINE_JUDGE
 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 #endif
   
   ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    
   
	prec();

   int T=1;cin >> T;
   while(T--)solve();
  
	#ifdef DEBUG
		cerr << "Runtine is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
    
    return 0;
    
    }
