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
	 int msum,psum,ssum,tot;
	node(int x=0){
		tot=x;
		x=max(x,0LL);
		msum=x;
		psum=x;
		ssum=x;
		
	}
};

int n,q;
int arr[200100];
node t[800400];//4*n;

node merge(node a,node b){
  node ans;
  ans.msum=max({a.msum,b.msum,a.ssum+b.psum});
  ans.psum=max({a.psum,a.tot+b.psum});
  ans.ssum=max({b.ssum,b.tot+a.ssum});
  ans.tot=a.tot+b.tot;
  return ans;

}

void build(int index,int l,int r){
	if(l==r){
		t[index]=node(arr[l]);
		return;
	}
	int mid=(l+r)/2;
	build(index*2,l,mid);
	build(index*2+1,mid+1,r);
	t[index]=merge(t[index*2],t[index*2+1]); //merging child nodes;
}

void update(int index,int l,int r,int pos,int value){
	 if(pos<l || pos>r) return;
	if(l==r){			//update
		//arr[pos]=value;
		t[index]=node(value);
		return;
	}
	int mid=(l+r)/2;
	update(index*2,l,mid,pos,value);
	update(index*2+1,mid+1,r,pos,value);
	t[index]=merge(t[index*2],t[index*2+1]); //merging child node;
}

node query(int index,int l,int r,int lq,int rq){
	if(l>rq or lq>r)return node();
	 if(lq<=l and r<=rq){
	 	return t[index];
	 }
	int mid=(l+r)/2;
	return merge(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));//merge
}


 //newtemplate
int n, q;
struct node
{
    int mxu, mnu, mxv, mnv;
    node () : mxu(-inf), mnu(inf), mxv(-inf), mnv(inf) {}
    node (int u, int v)
    {
        mxu = u, mnu = u;
        mxv = v, mnv = v;
    }
};
node merge (const node &a, const node &b)
{
    node ans;
    ans.mxu = max (a.mxu, b.mxu);
    ans.mnu = min (a.mnu, b.mnu);
    ans.mxv = max (a.mxv, b.mxv);
    ans.mnv = min (a.mnv, b.mnv);
    return ans;
}
struct SegmentTree
{
    node tr[N << 2];
    void modify (int u, int l, int r, int x, int U, int V)
    {
        if (l == r)
        {
            tr[u] = node (U, V);
            return ;
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
            modify (lc, l, mid, x, U, V);
        else
            modify (rc, mid + 1, r, x, U, V);
        tr[u] = merge (tr[lc], tr[rc]);
    }
    node query (int u, int l, int r, int x, int y)
    {
        if (x > y || x > r || y < l)
            return node ();
        if (x <= l && y >= r)
            return tr[u];
        int mid = (l + r) >> 1;
        return merge (query (lc, l, mid, x, y), query (rc, mid + 1, r, x, y));
    }
} seg;
