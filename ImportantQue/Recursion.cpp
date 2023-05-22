#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for(int i = a; i < int(n);i++ )
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ll              long long 
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
#define mp 				make_pair
#define lb lower_bound
#define ub upper_bound

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
 
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }
ll n;
ll ans=0;

bool is_good(ll val){
	int cnt[1000];
	memset(cnt,0,sizeof(cnt));
	while(val){
		cnt[val%10]++;
		val/=10;
	}

 return (cnt[3]>0 and cnt[5]>0 and cnt[7]>0);
}

void digit(ll val){
	if(val>n)return ;
	if(is_good(val))ans++;

	digit(val*10+3);
	digit(val*10+5);
	digit(val*10+7);
}
 //# int from(1 to n) that contain only 7,5,3 digits;

void solve(){
	cin>>n;
	digit(0);
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
 
   int T=1;//cin >> T;
   while(T--)solve();
  
	#ifdef DEBUG
		cerr << "Runtine is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
    
    return 0;
    
    }
