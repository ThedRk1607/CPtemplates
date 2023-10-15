const int N=1e6+5;


void solve(){
	int n;cin>>n;
	map<int,int>mp;
	FOR(i,0,n){
		int x,y;cin>>x>>y;
		mp[x]=y;
	}
	vector<int>dp(N,0);
	int mx=0;
     if(mp[0]>0)dp[0]=1;
	for(int x=1;x<=N;x++){
		if(!mp.count(x))dp[x]=dp[x-1];
		else {
			if(mp[x]>=x)dp[x]=1;
			else dp[x]=dp[x-mp[x]-1]+1;
		}

		amax(mx,dp[x]);
	}

cout<<n-mx<<nl;
