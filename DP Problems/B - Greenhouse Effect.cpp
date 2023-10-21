const int N=5005;
int dp[N];
void solve(){
	int n,m;cin>>n>>m;
	vector<pair<int,double>>p(n);
	for(int i=0;i<n;i++){
		int x;double y;cin>>x>>y;
		p[i]={x,y};
	}


//memset(dp,1,sizeof(dp));
 dp[0]=1;
	for(int i=1;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(p[i].F>=p[j].F)dp[i]=max(dp[i],dp[j]+1);
		}
	}
		
int ans=0;
for(int i=0;i<n;i++)amax(ans,dp[i]);
cout<<n-ans<<nl;

}

