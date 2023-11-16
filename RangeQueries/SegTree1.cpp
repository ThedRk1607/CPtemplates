const int N=2<<17;

struct node{
	ll max_val;
	node(){
		max_val=0;
	}
};
int arr[N];
node t[4*N];

node merge(node a,node b){
	node ans;
	ans.max_val=max(a.max_val,b.max_val);
	return ans;
}

void build(int id,int l,int r){
	if(l==r){
		//leaf node
		t[id].max_val=arr[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	t[id]=merge(t[2*id],t[2*id+1]);
}

void update(int id,int l,int r,int pos,ll val){
	if(pos<l or pos>r){
		return ;
	}
	if(l==r){
		t[id].max_val-=val;
		return;
	}
	int mid=(l+r)/2;
	update(2*id,l,mid,pos,val);
	update(2*id+1,mid+1,r,pos,val);
	t[id]=merge(t[2*id],t[2*id+1]);
}

node query(int id,int l,int r,int lq,int rq){
	if(lq>r or l>rq){
		return node();
	}
	if(lq<=l and r<=rq){
		return t[id];
	}
	int mid=(l+r)/2;
	return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));


}

void solve(){
	int n,q;cin>>n>>q;
	vl a(n);FORR(x,a)cin>>x;
	build(1,0,n-1);
	while(q--){
		int ch;cin>>ch;
		if(ch==1){
			ll a,b,u;cin>>a>>b>>u;
			a--,b--;
			update(1,0,n-1,a,u);
			update(1,0,n-1,b+1,-u);
		}else{
			int k;cin>>k;
			
		}
	}
}
