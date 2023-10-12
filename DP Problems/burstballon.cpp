const int N=105;
vector<vector<int>>dp(N,vector<int>(N));

void solve(){
	
	int n;cin>>n;
	vi v(n);FORR(x,v)cin>>x;

	for(int L=n-1;L>=0;L--){
		for(int R=L;R<n;R++){
			for(int i=L;i<=R;i++){
				int cost=v[i];
				if(L>0)cost*=v[L-1];
				if(R+1<n)cost*=v[R+1];
				if(L<=i-1)cost+=dp[L][i-1];
				if(i+1<=R)cost+=dp[i+1][R];
				dp[L][R]=max(dp[L][R],cost);

			}
		}
	}
	cout<<dp[0][n-1];


}

