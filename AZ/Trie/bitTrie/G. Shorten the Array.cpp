//link-https://codeforces.com/contest/2093/problem/G
struct trie{
	trie*child[2];int last=-1;
	trie(){
		child[0]=child[1]=NULL;last=-1;
	}
};

void insert(trie*node,int x,int id){
	trie*root=node;
	amax(root->last,id);
	for(int b=30;b>=0;b--){
		int bt=(x>>b&1);
		if(root->child[bt]==NULL){
			root->child[bt]=new trie();
		}
		root=root->child[bt];
		amax(root->last,id);
	}
}

int find(trie*node,int x,int k){
	int res=-1;bool ok=true;trie*root=node;
	for(int b=30;b>=0 and ok;b--){
		int bx=(x>>b)&1;
		int bk=(k>>b)&1;
		if(bk==1){
			if(root->child[bx^1]==NULL){ok=false;}
			else {
				root=root->child[bx^1];
			}
		}else{
			if(root->child[bx^1]){
				res=max(res,root->child[bx^1]->last);
			}
			if(root->child[bx]){
				root=root->child[bx];
			}else{
				ok=false;
			}

		}
	}
	if(ok){
		res=max(res,root->last);
	}
	return res;
}

void solve(){
	int n,k;cin>>n>>k;
	trie*T=new trie();
	int ans=n+1;
	rep(i,0,n){
		int x;cin>>x;
		insert(T,x,i);
		int y=find(T,x,k);
		if(y!=-1){
			amin(ans,i-y+1);
		}
		
	}
	if(ans==n+1)ans=-1;
	cout<<ans<<nl;
}
