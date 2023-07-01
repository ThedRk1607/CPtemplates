
ap<int,int>dp;

void solve(){
	ll n;cin>>n;
	vl v(n+1);
	FOR(i,1,n+1)cin>>v[i];
	//ZERO(dp);
	dp[0]=0;
	
	int ans=0,last;
	

	for(int i=1;i<=n;i++){
		int x=v[i];
		dp[x]=dp[x-1]+1;
		if(ans<dp[x]){
			ans=dp[x];
			last=x;
		}
	}

vl res;
for(int i=n;i>=1;i--){
	if(v[i]==last){
		res.pb(i);
		last--;
	}
}
reverse(all(res));
cout<<res.size()<<nl;
FORR(x,res)cout<<x<<" ";
}
