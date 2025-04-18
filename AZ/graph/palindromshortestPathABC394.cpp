#include <bits/stdc++.h>
using namespace std;


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// typedef pair<int, int> node;
// typedef tree<node, null_type, less_equal<node>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define rep(i,a,b)for(int i=a;i<b;i++)	
#define repp(x,arr) for(auto& x:arr)

#define ll              long long
#define ull              unsigned long long 
#define int ll
#define db              double
#define pb              push_back
#define all(v)             v.begin(),v.end()
#define F               first
#define S               second
#define mod              998244353
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
#define PQS priority_queue<int,vector<int>,greater<int>> 
#define ZERO(a) memset(a,0,sizeof(a))
#define inf 0x3f3f3f3f
//#define size(t) t.size()
using vi = vector<int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
const int dx[4] = {1,0,0,-1}, dy[4] = {0,-1,+1,0}; // for every grid problem!!
const int dx4[4] = {-1,1,1,-1}, dy4[4] = {-1,1,-1,1};

const int dx1[8] = {2,2,-2,-2,1,-1,1,-1}, dy1[8] = {-1,1,+1,-1,2,2,-2,-2};
const int dxn[8]={1,0,-1,0,-1,1,-1,1},dyn[8]={0,1,0,-1,-1,1,1,-1};
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }
template <typename A, typename B> A mod1 (A &a, B b){ a=(a%b+b)%b ; return a; }
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T> >;

int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isleap(int by){return (by%4==0 && (by%100!=0 || by%400==0));};
inline int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);}
inline int lcm(int x,int y){return x*y/gcd(x,y);}


inline int mul(int a, int b) { return (int) ((long long) (a%mod * b%mod) % mod);}
inline int add(int a,int b){return (a%mod+b%mod)%mod;}
inline int sub(int a,int b){return (a-b+mod)%mod;}
inline int binpow(int a,int b){
    int res=1;a%=mod;
    while(b){if(b&1)res=res*a%mod;a=a*a%mod;b/=2;}
    return res%mod;
}
inline int inv(int a){return binpow(a,mod-2)%mod;}




void solve(){
 	int n;cin>>n;
 	vs c(n);
 	repp(x,c)cin>>x;
 	vector<vi>dis(n+1,vi(n+1,inf));
 	queue<pii>q;

 	rep(i,0,n){
 		q.push({i,i});dis[i][i]=0;//0-len pal 
 	}
 	rep(i,0,n){
 		rep(j,0,n){
 			if(i!=j and c[i][j]!='-'){
 				q.push({i,j});
 				dis[i][j]=1;//1-len pal
 			}
 		}
 	}
//now we extend pal a(i-j)a and add dis+2;
 	while(!q.empty()){
 		auto it=q.front();q.pop();
 		int i=it.F,j=it.S;
 		rep(k,0,n){
 			rep(l,0,n){
 				if(c[k][i]!='-' and c[j][l]!='-' and c[k][i]==c[j][l] and dis[k][l]==inf){
 					q.push({k,l});
 					dis[k][l]=dis[i][j]+2;
 				}
 			}
 		}
 	}

 	rep(i,0,n){
 		rep(j,0,n)if(dis[i][j]==inf)cout<<"-1 ";else cout<<dis[i][j]<<" ";
 		cout<<nl;
 	}
 	
 }

 



int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

   
   ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    // function<void(int)> dfs = [&](int i) {
     
    //   dfs(i);
    // };
    	
   int T=1;//cin >> T;//int c=1;
   while(T--)solve();
  
    
    return 0;
    
    }
