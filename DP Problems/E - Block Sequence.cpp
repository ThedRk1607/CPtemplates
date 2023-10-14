
void solve(){
	int n;cin>>n;
	vl v(n);FORR(x,v)cin>>x;
	vector<int>dp(n+1,1e9);
	dp[0]=1;
	if(v[0]<n)dp[0+v[0]]=0;
	for(int i=1;i<n;i++){
		dp[i]=min(dp[i],dp[i-1]+1);//remove element
			if(i+v[i]<n)dp[i+v[i]]=min(dp[i+v[i]],dp[i-1]); //not remove and start block from i;
			

	}

cout<<dp[n-1]<<nl;

}
