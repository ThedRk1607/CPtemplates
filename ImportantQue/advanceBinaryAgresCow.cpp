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

const int M=1e9+7;
const int N=1e5+5;
int n,c;
int x[N];

bool check(int d){//d is mininum distance 
	int last=-M; //the last stall in which a cow was placced;
	int cnt=0;
	FOR(i,0,n){
		if(x[i]-last>=d){
			cnt++;
			last=x[i];
		}
	}

	if(cnt>=c)return true;
	else return false;

}

void solve(){

	cin>>n>>c;
	FOR(i,0,n)cin>>x[i];
	sort(x,x+n);

	/*//linerar search;
	FOR(i,1,N){
		if(check(i)==false){
			cout<<i-1<<nl;
			return;
		}
	}*/

	int l=1,r=M;
 int ans;
	while(l<=r){
		int md=(l+r)/2;
		if(check(md)){
			ans=md;
			l=md+1;
		}else r=md-1;
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
 
   int T=1;//cin >> T;
   while(T--)solve();
  
	#ifdef DEBUG
		cerr << "Runtine is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
    
    return 0;
    
    }
