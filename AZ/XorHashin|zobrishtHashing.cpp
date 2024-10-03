This is similar to a method called Zobrist hashing, which uses the xor-sum of randomized hashes to quickly compare sets.
However, since we are comparing multisets rather than sets, we use addition instead of xor.

const int N=2e5+5;
int hs[N],sa[N],sb[N];

void solve(){
	int n,q;cin>>n>>q;
	rep(i,1,n+1)hs[i]=rand();
	rep(i,0,n){
		int a;cin>>a;
		sa[i+1]=sa[i]+hs[a];
	}
	rep(i,0,n){
		int b;cin>>b;
		sb[i+1]=sb[i]+hs[b];
	}

	while(q--){
		int l,r,L,R;cin>>l>>r>>L>>R;
		int x=sa[r]-sa[l-1];
		int y=sb[R]-sb[L-1];
		if(x==y)cout<<"Yes\n";
		else cout<<"No\n";
	}

}
