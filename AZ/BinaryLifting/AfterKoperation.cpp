void solve(){
	int n,k;cin>>n>>k;
	vector<vector<int>>p(60,vector<int>(n+1));//it is ith element after 2^k operations;
	rep(i,1,n+1)cin>>p[0][i];//at 1 operations

	for(int lv=1;lv<60;lv++){
		for(int i=1;i<=n;i++){
			p[lv][i]=p[lv-1][p[lv-1][i]];
		}
	}
	vi q(n+1); //ith element after kth operations
	rep(i,1,n+1)q[i]=i; //at 0 operations
	for(int lv=0;lv<60;lv++){
		if(k%2){
			for(int i=1;i<=n;i++){
				q[i]=p[lv][q[i]];
			}
		}
		k/=2;
	}
	
	cout<<q[1]<<nl;
}
