
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


   
void solve(){
	 int n;cin>>n;
   string a,b;cin>>a>>b;
  
   if(a==b){
   	cout<<"0"<<nl;
   	return;
   }
  
  //make a==b;
   ll changes=0;
   FOR(i,0,n)changes+=(a[i]!=b[i]);

   ll ans=INF;

   if(changes&1){
   	amin(ans,2*changes-1); //so we already have a==b;
   }else amin(ans,2*changes); //if m1 is even and one move bob isleft ;

   //making s1=rev(s2);
   reverse(all(b));
   changes=0;
   FOR(i,0,n){
   	changes+=(a[i]!=b[i]);
   }
   if(changes==0)amin(ans,2LL);
   else if(changes%2==0)amin(ans,2*changes-1);
   else amin(ans,2*changes);

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
 
   int T=1;cin >> T;
   while(T--)solve();
  
	#ifdef DEBUG
		cerr << "Runtine is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
    
    return 0;
    
    }
