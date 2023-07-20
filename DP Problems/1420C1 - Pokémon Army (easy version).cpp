
void solve(){
	int n,q;cin>>n>>q;
	vi v(n);FORR(x,v)cin>>x;
	ll dp1[n+1],dp2[n+1];
	ZERO(dp1);//for sol for odd length;
	ZERO(dp2);//sol for even length;
	dp1[0]=-1e18;
	for(int i=1;i<=n;i++){
		dp1[i]=max(dp1[i-1],dp2[i-1]+v[i-1]);
		dp2[i]=max(dp2[i-1],dp1[i-1]-v[i-1]);

	}

	cout<<max(dp1[n],dp2[n])<<nl;
}

	
