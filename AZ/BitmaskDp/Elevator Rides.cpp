int n,x;
int w[N];
 pii dp[(1<<N)];
pii rec(int mask){
	if(mask==0){
		return {1,0};
	}
	if (dp[mask].F != -1 && dp[mask].S != -1) return dp[mask];
	pii ans={inf,inf};
	for(int i=0;i<n;i++){
		if(!(mask>>i&1))continue;
		pii cur=rec(mask^(1<<i));
		ans=min(ans,{cur.F+(cur.S+w[i]>x),(cur.S+w[i])>x?w[i]:cur.S+w[i]});
	}
	return dp[mask]=ans;
}



void solve(){
  cin>>n>>x;
  rep(i,0,n)cin>>w[i];

  rep(i,0,1<<n)dp[i].F=dp[i].S=-1;
  cout<<rec((1<<n)-1).F<<nl;
  
}
	
