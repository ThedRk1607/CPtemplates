#include <bits/stdc++.h>
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
#define PQS priority_queue<ll,vector<ll>,greater<ll>> 
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

const int N=301;

double dp[N][N][N];
//dp[x][y][z] x 3s,y 2s,z 1s,n-x-y-z 0s;




void solve()
{
	int n;cin>>n;
	int cnt[4]={0};
	for(int i=0;i<n;i++){
	int x;cin>>x;
	cnt[x]++;
}

dp[0][0][0]=0;

for(int three=0;three<=n;three++){
	for(int two=0;two<=n;two++){
		for(int one=0;one<=n;one++){
			int zero=n-three-two-one;
			if(zero==n)continue;
			if(one+two+three>n)continue;

			double val=1;
			//pick 3;
			if(three>0)val+= (1.0*three/n)*dp[three-1][two+1][one];
			if(two>0)val+=(1.0*two/n)*dp[three][two-1][one+1];
			if(one>0)val+=(1.0*one/n)*dp[three][two][one-1];
			dp[three][two][one]=val/(1-1.0*zero/n);
		}
	}
}
cout<<setprecision(13)<<fixed;
cout<<dp[cnt[3]][cnt[2]][cnt[1]];
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
