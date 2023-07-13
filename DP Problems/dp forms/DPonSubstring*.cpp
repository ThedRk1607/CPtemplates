
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
#define PQS priority_queue<int,vector<int>,greater<int>> 
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

int dp[100100][16];
string t="1101";
int n; 

int rec(int level,int lastthree){

	//basecase
	if(level==n)return 1;

	if(dp[level][lastthree]!=-1)return dp[level][lastthree];

	int ans=0;
	if(level>=3 and lastthree==2){//010;
		//dont allow
		ans=rec(level+1,5);
	}else {
		//add a zero
		ans=rec(level+1,(lastthree<<1|0)&7); //and 7 for maintain last
											//	three bits or (111);
		ans+=rec(level+1,(lastthree<<1|1)&7);
	}
	//cout<<ans<<nl;
	return dp[level][lastthree]=ans;
}

//anotther way usign some finite automata concept advance;
//with five match state 
int ok(int level,int match){
		if(match==4)return 0;
		if(level==n)return 1;

		if(dp[level][match]!=-1)return dp[level][match];

		int ans=0;//match set acc to automata states;
		if(match==0){
			ans=rec(level+1,0)+rec(level+1,1);
		}else if(match==1){
			ans=rec(level+1,1)+rec(level+1,2);
		}else if(match==2){
			ans=rec(level+1,3)+rec(level+1,0);
		}else if(match==3){
			ans=rec(level+1,4)+rec(level+1,2);
		}

		return dp[level][match]=ans;
}

void solve(){
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0);
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
