
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
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
 
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const int N=2014;
ll d1[2*N],d2[2*N];
ll sol[2];
pll v[2];

ll grid[N][N];

void update(ll c,ll i,ll j,ll val){
	if(val>sol[c]){
		sol[c]=val;
		v[c].F=i;
		v[c].S=j;
	}
}




void solve(){
	ll n;   cin>>n;
	sol[0]=sol[1]=-1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			//int x;cin>>x;
			cin>>grid[i][j];
			d1[i+j]+=grid[i][j];
			d2[i-j+n]+=grid[i][j];

		}
	}

FOR(i,1,n+1)
	FOR(j,1,n+1)
		update((i+j)&1,i,j,d1[i+j]+d2[i-j+n]-grid[i][j]);



	
cout<<sol[0]+sol[1]<<nl;
if(v[0]>v[1])swap(v[0],v[1]);
cout<<v[0].F<<" "<<v[0].S<<' '<<v[1].F<<" "<<v[1].S<<nl;

   
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
