#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for(int i = a; i < int(n);i++ )
#define FORR(x,arr) for(auto& x:arr)
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
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
 
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

int n;
int queen[20]; //queen[i] where is q at row i;
char grid[8][8];
bool vis[8][8];

void disp(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(vis[i][j])cout<<"Q ";
			else cout<<"X ";
		}
		cout<<nl;
	}
	cout<<nl;
}

bool check(int row,int col){
	for(int i=0;i<row;i++){
		int prow=i;
		int pcol=queen[i];
		if(pcol==col or abs(col-pcol)==abs(row-prow))return 0;

	}
	return 1; 
}

int rec(int level){
	if(level==n){
		disp();
		return 1;
	}

	//choice or transition
	int ans=0;
	for(int col=0;col<n;col++){
		if(check(level,col)){
			if(grid[level][col]=='*')continue;
			//place the queen 
			queen[level]=col;
			vis[level][col]=1;
			//explore the options;
			ans+=rec(level+1);
			//backtrack if not work
			//queen[level]=-1;
			//vis[level][col]=0;
		}
	}
	return ans;
}

void solve(){
n=8;
FOR(i,0,8)FOR(j,0,8)cin>>grid[i][j];
MINUS(queen);
cout<<rec(0);
// for(int i=0;i<n;i++){
// 	int x=queen[i];
// 	//cout<<x<<nl;
// 	for(int j=0;j<n;j++){
// 			if(x==j)cout<<"Q ";
// 			else cout<<"0 ";
// 	}
// 	cout<<nl;
// }

  
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
