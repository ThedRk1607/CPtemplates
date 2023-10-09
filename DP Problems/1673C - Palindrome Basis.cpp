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

const int mod=1e9+7;
const int N=40004,M=502;
 ll dp[N][M];


int reverse(int n){
	int r=0;
	while(n>0){
		r=r*10+n%10;
		n/=10;
	}
	return r;

}

bool ispal(int n){return (reverse(n)==n);}

void pre(){
	vi pal;
 	pal.pb(0);
 	FOR(i,1,2*N)if(ispal(i))pal.pb(i);
 	//ZERO(dp);
 	
 	FOR(i,1,M)dp[0][i]=1;

 	for(int i=1;i<N;i++){
 		dp[i][0]=0;
 		for(int j=1;j<M;j++){
 			dp[i][j]=dp[i][j-1];
 			if(pal[j]<=i)(dp[i][j]+=dp[i-pal[j]][j])%=mod;
 		}
 	}
 	
}

 void solve(){
 	int n;cin>>n;
 	
   cout<<dp[n][M-1]<<nl;

 }

int32_t main()
{
 
	#ifndef ONLINE_JUDGE
 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 #endif
   
   ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    
    pre();
	

   int T=1;cin >> T;
   while(T--)solve();
  
	#ifdef DEBUG
		cerr << "Runtine is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
    
    return 0;
    
    }
