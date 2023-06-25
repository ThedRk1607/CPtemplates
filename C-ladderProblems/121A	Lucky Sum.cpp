
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
const int dxn[8]={1,0,-1,0,-1,1,-1,1},dyn[8]={0,1,0,-1,-1,1,1,-1};
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const int mxn=1024;
ll luck[mxn];

int f(int x){
	if(x==0)return 0;
	ll ans=0;

	for(int i=1;i<=mxn;i++){
		if(luck[i]<x){
			ans+=luck[i]*(luck[i]-luck[i-1]);
		}else {
			ans+=luck[i]*(x-luck[i-1]);
			break;
		}
	}
	return ans;
}

void solve(){
ll l,r;cin>>l>>r;
luck[1]=4;
luck[2]=7;
int t=3;

for(int i=1;i<512;i++){
	luck[t++]=luck[i]*10+4;
	luck[t++]=luck[i]*10+7;
}

cout<<f(r)-f(l-1)<<nl;

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
