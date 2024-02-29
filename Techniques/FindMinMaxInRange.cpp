	//amortized time complexity ;
	struct monotone_deque{
		deque<int>dq;
		void insert(int x){
			while(!dq.empty() and dq.back()<x)dq.pop_back();
				dq.pb(x);
		}
		void remove(int x){
			if(dq.front()==x)dq.pop_front();
		}
		int getmin(){
			return dq.front();
		}

	};

void solve(){
	int n,k;cin>>n>>k;
	vi v(n);repp(x,v)cin>>x;
	monotone_deque mdq;

	 rep(i,0,n){
	 	mdq.insert(v[i]); //O(1);
	 	if(i>=k)mdq.remove(v[i-k]);
	 	if(i>=k-1)cout<<mdq.getmin()<<" ";
	 }
}
