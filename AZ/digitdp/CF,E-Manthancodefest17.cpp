int a[70],dp[15][70][1030],n,up,l,r,b;

//p is leading zero inprefix and r is mask that contain #odd digits;
int dfs(int pos,int r,int p,bool flag){
	if(pos==0){
		return r==0;
	}
	if(~dp[b][pos][r] and !p&&!flag)return dp[b][pos][r];
	int ans=0,up=(flag?a[pos]:b-1);
	for(int i=0;i<=up;i++){
		ans+=dfs(pos-1,(p&&!i)?0:(r^(1LL<<i)),p&&!i,flag&&(i==up));
	}
	if(!p&&!flag)dp[b][pos][r]=ans;
	return ans;

}

int calc(int x){
	n=0;
	while(x)a[++n]=x%b,x/=b;
	return dfs(n,0,1,1);
}

void solve(){
	memset(dp,-1,sizeof(dp));
	int q;cin>>q;
	while(q--){
		cin>>b>>l>>r;
	int ans=calc(r)-calc(l-1);
	cout<<ans<<nl;
	}
}
