#include <bits/stdc++.h>
using namespace std;
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
#define mod            1000000007
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
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
//const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
//const int dxn[8]={1,0,-1,0,-1,1,-1,1},dyn[8]={0,1,0,-1,-1,1,1,-1};
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

class LRUCache {
	list<int>order;
	unordered_map<int,pair<int,list<int>::iterator>>cache;
	int maxsize=0;

	void touch(int id){
		auto it=cache.find(id);
		int key=it->first;
		order.erase(it->second.second);
		order.push_front(key);
		it->second.second=order.begin();
	}
public:
	LRUCache(int capacity){
		maxsize=capacity;
		order.clear();
		cache.clear();
	}

	int get(int key){
		if(cache.find(key)==cache.end())return -1;
		else{
			touch(key);
			return cache[key].first;
		}
	}

	void put(int key,int value){
		if(cache.find(key)==cache.end()){
			if(cache.size()==maxsize){
				int del=order.back();
				cache.erase(del);
				order.pop_back();
			}
			order.push_front(key);
		}else{
			touch(key);
		}
		cache[key]={value,order.begin()};
	}
};

void solve(){
 	int n,k;cin>>n>>k;
 	LRUCache ds(k);
 	while(n--){
 		string s;cin>>s;
 		if(s=="put"){
 			int key,value;cin>>key>>value;
 			ds.put(key,value);

 		}else if(s=="get"){
 			int key;cin>>key;
 			cout<<ds.get(key)<<nl;
 		}
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

 	
 	
   int T=1;//cin >> T;
   while(T--)solve();
  
	
    return 0;
    
    }
