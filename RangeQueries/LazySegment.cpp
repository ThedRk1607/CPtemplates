const int N=2<<17;

struct node{
	int lazy; //we need two operation same time need two lazy;
	//int lazy_set;
	int sum;
	node(){
		lazy=0;
		//lazy_set=0;
		sum=0;
	}
};

node merge(node a,node b){
	node ans;
	 ans.sum=a.sum+b.sum;
	 return ans;
}
int arr[N];
node t[2*N];
void push(int id,int l,int r){
	if(t[id].lazy){
		//if there is lazy,apply and pushdown
		t[id].sum+=(r-l+1)*t[id].lazy;
		//pushdown logic if not leaf;
		if(l!=r){
			t[id<<1].lazy+=t[id].lazy;
			t[id<<1|1].lazy+=t[id].lazy;
		}
		//clear;
		t[id].lazy=0;
	}
}

void build(int id,int l,int r){
	if(l==r){
		//leaf node
		t[id].sum=arr[l];
		t[id].lazy=0;
		return;
	}
	int mid=(l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	t[id]=merge(t[2*id],t[2*id+1]);
}

void update(int id,int l,int r,int lq,int rq,ll val){
	push(id,l,r);
	if(lq>r or l>rq)return;
	if(lq<=l and r<=rq){
		t[id].lazy+=val;
		push(id,l,r);
		return;

	}
	int mid=(l+r)/2;
	update(2*id,l,mid,lq,rq,val);
	update(2*id+1,mid+1,r,lq,rq,val);
	t[id]=merge(t[2*id],t[2*id+1]);
}

node query(int id,int l,int r,int lq,int rq){
	push(id,l,r);
	if(lq>r or l>rq){
		return node();
	}
	if(lq<=l and r<=rq){
		return t[id];
	}
	int mid=(l+r)/2;
	return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));

}
