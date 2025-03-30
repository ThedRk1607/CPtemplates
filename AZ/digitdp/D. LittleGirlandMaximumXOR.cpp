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
#define PQS priority_queue<ll,vector<ll>,greater<ll>> 
#define ZERO(a) memset(a,0,sizeof(a))
#define inf 0x3f3f3f3f


using vi = vector<int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const int dxn[8]={0,1,1,1,0,-1,-1,-1},dyn[8]={1,1,0,-1,-1,-1,0,1};
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
while(b){if(b&1)res=res*a%mod;a=a*a%mod;b/=2;}
return res;
}
inline int inv(int a){return binpow(a,mod-2)%mod;}


const int MAXLOG=70;


int a, b;
int dp[MAXLOG][2][2][2][2];

int rec(int i, int j, int k, int l, int m)
{
  if (i < 0)
    return (j && k && l && m) ? 0LL : 0LL;
  if (dp[i][j][k][l][m] != -1)
    return dp[i][j][k][l][m];
  int ret = 0;
  int L = a & (1LL << i);
  int R = b & (1LL << i);
  if ((j || !L) && (l || !L))
    ret =max(ret,rec(i - 1, j, (R) ? 1 : k, l, (R) ? 1 : m));
  if ((k || R) && (l || !L))
    ret =max(ret,rec(i - 1, (!L) ? 1 : j, k, l, (R) ? 1 : m)+(1LL<<i));
  if ((m || R) && (j || !L))
    ret =max(ret,rec(i - 1, j, (R) ? 1 : k, (!L) ? 1 : l, m)+(1LL<<i));
  if((k || R) and (m || R))
  	ret=max(ret,rec(i-1,(!L) ? 1 : j,k,(!L) ? 1 : l,m));
  return dp[i][j][k][l][m] = ret;
}

void solve(){
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	int N=log2(b);
	cout<<rec(N,0,0,0,0);	

}


	



int32_t main()
{
 	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif


   
   ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);


 
  	
   int T=1;//cin >> T;
   while(T--)solve();
  


    return 0;
    
    }
