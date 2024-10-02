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
#define mod             1000000007
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
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const int dxn[8]={0,1,1,1,0,-1,-1,-1},dyn[8]={1,1,0,-1,-1,-1,0,1};
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

struct node{
	int sum,lazyset,lazysum;
	node(int a=0,int b=0,int c=0){
		sum=a;
		lazysum=b;
		lazyset=c;
	}
};


int n,q;
int arr[200100];
node t[800400];//4*n;

node merge(node a,node b){
	node ans;
	ans.sum=a.sum+b.sum;
	return ans;
}

void build(int index,int l,int r){
	if(l==r){
		t[index].sum=arr[l];
		return;
	}
	int mid=(l+r)/2;
	build(index*2,l,mid);
	build(index*2+1,mid+1,r);
	t[index]=merge(t[index*2],t[index*2+1]); //merging child nodes;b
}

 void push(int id,int l,int r){
 	if(t[id].lazyset){
 		t[id].sum=(r-l+1)*t[id].lazyset;
 		if(l<r){ //not leaf node
 			t[id*2].lazyset=t[id*2+1].lazyset=t[id].lazyset;
 			t[id*2].lazysum=t[id*2+1].lazysum=0;
 		}
 		t[id].lazyset=0;
 	}
 	if(t[id].lazysum){
 		t[id].sum+=(r-l+1)*t[id].lazysum;
 		if(l<r){
 			t[id*2].lazysum+=t[id].lazysum;
 			t[id*2+1].lazysum+=t[id].lazysum;
 		}
 		t[id].lazysum=0;
 	}
 }

void update(int index,int l,int r,int lq,int rq,int value,bool set){
	 push(index,l,r);
	 if(r<lq or l>rq) return;
	if(lq<=l and r<=rq){
		if(set){
			t[index].lazysum=0;
			t[index].lazyset=value;
		}else{
			t[index].lazysum+=value;
		}
		 push(index,l,r);
		 return;
	}
	int mid=(l+r)/2;
	update(index*2,l,mid,lq,rq,value,set);
	update(index*2+1,mid+1,r,lq,rq,value,set);
	t[index]=merge(t[index*2],t[index*2+1]);
}



node query(int index,int l,int r,int lq,int rq){
	 
	 if(r<lq or l>rq) return node(); push(index,l,r);
	if(lq<=l and r<=rq){
		return t[index];
	}
	int mid=(l+r)/2;
	return merge(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
	
}


void solve(){
	cin>>n>>q;
	rep(i,0,n)cin>>arr[i];
	build(1,0,n-1);
	
	while(q--){
		int t;cin>>t;
		if(t==1){
			int a,b,x;cin>>a>>b>>x;
			update(1,0,n-1,a-1,b-1,x,0);
		}else if(t==2){
			int a,b,x;cin>>a>>b>>x;
			update(1,0,n-1,a-1,b-1,x,1);
		}else{
			int a,b;cin>>a>>b;
			node ans=query(1,0,n-1,a-1,b-1);
			cout<<ans.sum<<nl;
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

