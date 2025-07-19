
#include <bits/stdc++.h>
using namespace std;



#define rep(i,a,b)for(int i=a;i<b;i++)
#define repp(x,arr) for(auto& x:arr)

#define ll              long long 
#define int ll
#define ull              unsigned long long 

#define db              double
#define pb              push_back
#define all(v)             v.begin(),v.end()
#define F               first
#define S               second
#define mod              1000000007
#define popcount(x)     __builtin_popcountll(x)
#define zeroes(x) 			__builtin_clz(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define nl              "\n"
#define PI              3.1415926536 //acos(-1.0)
#define eps 0.00000001
#define mpp                 make_pair
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue<int> //by default provide largest element;
#define RS set <ll, greater <ll> >
#define PQS priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> 
#define ZERO(a) memset(a,0,sizeof(a))
#define inf 0x3f3f3f3f
#define len(x) (x.size())

using vi = vector<int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
//const int dx[4] = {1,-1,1,-1}, dy[4] = {1,-1,-1,1};
const int dxn[8]={1,-1,1,-1,1,0,-1,0},dyn[8]={1,-1,-1,1,0,1,0,-1};
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }
template <typename A, typename B> A mod1 (A &a, B b){ a=(a%b+b)%b ; return a; }


int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isleap(int by){return (by%4==0 && (by%100!=0 || by%400==0));};
inline int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);}


inline int mul(int a, int b) { return (int) ((long long) (a%mod * b%mod) % mod);}
inline int add(int a,int b){return (a%mod+b%mod)%mod;}
inline int sub(int a,int b){return (a-b+mod)%mod;}
inline int binpow(int a,int b){
	a%=mod;int res=1;
while(b){if(b&1)res=mul(res,a);a=mul(a,a);b/=2;}
return res;
}

inline int inv(int a){return binpow(a,mod-2)%mod;}

const int N=2010;
const double EPS = 1.0*(N-1)/N;
#define UP(x) (x + EPS)

string a[N];
int n,m,d;
int dp[N][N][2],sdp[N][N][2];

int getsum(int r,int c1,int c2,int f){
	int res=sdp[r][c2][f];
	if(c2)res-=sdp[r][c1-1][f];
	return res;

}

int get(int i,int j,int f){
	if(a[i][j]!='X')return 0;
	int res=0;if(i==n-1)res++;
	if(!f){
		res+=getsum(i,max(0LL,j-d),min(m-1,j+d),1);
		res-=dp[i][j][1];
	}
	if(i<n-1){
		res+=getsum(i+1,max(0LL,j-d+1),min(m-1,j+d-1),0);
	}
	return res%mod;
}



void solve(){
  cin>>n>>m>>d;
  rep(i,0,n)cin>>a[i];

  for(int i=n-1;i>=0;i--){
  	for(int f=1;f>=0;f--){
  		for(int j=0;j<m;j++){
  			sdp[i][j][f]=dp[i][j][f]=get(i,j,f);
  		}
  		for(int j=1;j<m;j++)sdp[i][j][f]+=sdp[i][j-1][f];
  	}
  }
  int ans=0;
  for(int j=0;j<m;j++)ans=add(ans,dp[0][j][0]);
  	cout<<ans<<nl;
 
 }


int32_t main()
{
 	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif


   
   ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

  //f();
   int T=1;cin >> T;
   while(T--)solve();
  


    return 0;
    
    }
