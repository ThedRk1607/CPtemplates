
int n;
string s;
int dp[1005];


void solve(){
	
	cin>>n>>s;
	memset(dp,-1,sizeof(dp));

	dp[0]=0;

	for(int i=1;i<n;i++){
		if(s[i]=='w')continue;
		int ans=0;
		if(dp[i-1]!=-1 ){
			amax(ans,dp[i-1]);
			dp[i]=0;
		}

		if(i>=3 and dp[i-3]!=-1){
			amax(ans,dp[i-3]);
			dp[i]=0;
		}
		if(i>=5 and dp[i-5]!=-1){
			amax(ans,dp[i-5]);
			dp[i]=0;
		}

		if(dp[i]==0 and s[i]=='"')dp[i]++;
		dp[i]+=ans;
	}

	cout<<dp[n-1];

}
