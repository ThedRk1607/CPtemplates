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
#define PQ priority_queue<pii> //by default provide largest element;
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

struct data_dashboard{
	//mean
	int sum=0;
	int cnt=0;

	//varience
	int sumsq=0;

	//mode;
	map<int,int>freq;
	multiset<pii>freq_order;

	//median
	multiset<int>low,high;

	 void balance()
    {
        while (low.size() < high.size())
        {
            int x = *high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        while (low.size() > high.size() + 1)
        {
            int x = *low.rbegin();
            low.erase(low.find(x));
            high.insert(x);
        }
    }


	void insert(int x){
		sum=add(sum,x);
		cnt=add(cnt,1);
		sumsq=add(sumsq,x*x);
		 // mode
        if (freq_order.find(make_pair(freq[x], -x)) != freq_order.end())
        {
            freq_order.erase(freq_order.find(make_pair(freq[x], -x)));
        }
        freq[x]++;
        freq_order.insert(make_pair(freq[x], -x));

        // median
        if (low.empty())
        {
            low.insert(x);
        }
        else if (x <= (*low.rbegin()))
        {
            low.insert(x);
        }
        else
        {
            high.insert(x);
        }
        balance();


	}

	void remove(int x){
		sum=sub(sum,x);
		cnt=sub(cnt,1);
		sumsq=sub(sumsq,x*x);
		// remove mode
        if (freq_order.find(make_pair(freq[x], -x)) != freq_order.end())
        {
            freq_order.erase(freq_order.find(make_pair(freq[x], -x)));
        }
        freq[x]--;
        freq_order.insert(make_pair(freq[x], -x));

        // median
        if (high.find(x) != high.end())
        {
            high.erase(high.find(x));
        }
        else if (low.find(x) != low.end())
        {
            low.erase(low.find(x));
        }
        balance();
	}

	int mean(){
		if(cnt==0)return -1;
		return mul(sum,inv(cnt));
	}

	int varience(){
		if(cnt==0)return -1;
		return sub(mul(sumsq,inv(cnt)),mul(mean(),mean()));
	}

	int mode(){
		if(freq_order.empty())return -1;
		return -freq_order.rbegin()->S;
	}

	int median(){
		if((low.size()+high.size())==0)return -1;
		if((low.size()+high.size())%2){
			return *low.rbegin();
		}else{
			int y=(*low.rbegin()+(*high.begin()));
			 return mul(y,inv(2));
		}
	}
};


 void solve(){
 		int q;cin>>q;
 		data_dashboard db1;
 		while(q--){
 			string s;cin>>s;int x;
 			if(s=="insert"){
 				cin>>x;db1.insert(x);
 			}else if(s=="getMean")cout<<db1.mean()<<nl;
 			else if(s=="getMedian")cout<<db1.median()<<nl;
 			else if(s=="getMode")cout<<db1.mode()<<nl;
 			else if(s=="remove"){
 				cin>>x;
 				db1.remove(x);
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

 	
 	
   int T=1;cin >> T;
   while(T--)solve();
  
	
    return 0;
    
    }
