
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

const int N=3005;
int dp[N][N];
int choice[N][N];
//0->(i-1,j),1->(i,j-1),2->pick goto(i-1,j-1);

void solve(){

	string s,t;cin>>s>>t;
	int n=s.size();
	int m=t.size();

	
dp[0][0]=0;
if(s[0]==t[0]){
	dp[0][0]=1;
	choice[0][0]=2;
}



	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i){
				dp[i][j]=dp[i-1][j];
				choice[i][j]=0;
			}
			if(j){
				if(dp[i][j-1]>dp[i][j]){
					dp[i][j]=dp[i][j-1];
					choice[i][j]=1;
				}
				
			}
			 
			 if(s[i]==t[j]){
			 	int ans=1;
			 	if(i and j)ans=1+dp[i-1][j-1];
			 	if(ans>dp[i][j]){
			 		dp[i][j]=ans;
			 		choice[i][j]=2;

			 	}
			 }
			
			 
		}
	}

int x=n-1,y=m-1;
string subseq;
while(x>=0 and y>=0){
	if(choice[x][y]==0)x--;
	else if(choice[x][y]==1)y--;
	else if(choice[x][y]==2){
		subseq.pb(s[x]);
		x--;
		y--;
	}
}
reverse(all(subseq));
cout<<subseq<<nl;
	
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
