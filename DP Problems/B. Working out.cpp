
#include <bits/stdc++.h>
 
using namespace std;
 
 
#define forn(i,a,n) for(int i = a; i < int(n);i++ )
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
using ld = long double;
const ll N=1001;


ll dp1[N][N];
ll dp2[N][N];
ll dp3[N][N];
ll dp4[N][N];
ll a[N][N];

void solve(){
	int n,m;cin>>n>>m;
	forn(i,1,n+1){
		forn(j,1,m+1)cin>>a[i][j];
	}
dp1[0][0]=0;
dp2[0][0]=0;
dp3[0][0]=0;
for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
        dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
for (int j = m; j >= 1; --j)
    for (int i = 1; i <= n; ++i)
        dp2[i][j] = a[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
for (int i = n; i >= 1; --i)
    for (int j = 1; j <= m; ++j)
        dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
for (int i = n; i >= 1; --i)
    for (int j = m; j >= 1; --j)
        dp4[i][j] = a[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]);

  
  ll ans=0;
  for (int i = 2; i <= n - 1; i++)
		for (int j = 2; j <= m - 1; j++)
		{
			long long temp;
			temp = dp1[i][j - 1] + dp3[i + 1][j] + dp2[i - 1][j] + dp4[i][j + 1];
			temp = max(temp, dp1[i - 1][j] + dp3[i][j - 1] + dp2[i][j + 1] + dp4[i + 1][j]);
			ans = max(ans, temp);
		}
	cout << ans << endl;
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
