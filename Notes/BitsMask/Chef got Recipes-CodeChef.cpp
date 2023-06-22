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
 
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

ll F[32]; //5 set bits prodeuce 5 diff chars;
string st;

void solve(){
   int n;cin>>n;
   ZERO(F);
   for(int i=1;i<=n;i++){
   	 cin>>st;
   	   int mask=0;
   	 for(auto ch:st){
   	 		if(ch=='a')mask=mask | (1<<0);
   	 		if(ch=='e')mask = mask | (1<<1);
   	 		if(ch=='o')mask=mask | (1<<2);
   	 		if(ch=='i')mask=mask | (1<<3);
   	 		if(ch=='u')mask=mask | (1<<4);
   	 }

   	 F[mask]++;
   }


ll res=0;
   for(int i=1;i<32;i++){
   	for(int j=i+1;j<32;j++){
   		if((i | j)==31)res=res+(F[i]*F[j]);
   	}
   }

   res=res+(F[31]*(F[31]-1)/2);
   cout<<res<<nl;
}

int32_t main()
{
 
	#ifndef ONLINE_JUDGE
 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 #endif
   
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
   int T=1;cin >> T;
   while(T--)solve();
  
	#ifdef DEBUG
		cerr << "Runtine is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
    
    return 0;
    
    }
