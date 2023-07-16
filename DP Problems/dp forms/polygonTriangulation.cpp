
int n;
pair<double,double>p[102];

double sq(double x){
	return x*x;
}

double cost(int x,int y){
	double dist=sqrt(sq(p[x].F-p[y].F)+sq(p[x].S-p[y].S));
	return sin(dist);
}

	void solve(){
		cin>>n;
		FOR(i,1,n+1)cin>>p[i].F>>p[i].S;
		double dp[n+1][n+1];

		for(int len=3;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				if(len==3)dp[len][len]=0;

					double ans=1e9;
				for(int x=l+1;x<=r-1;x++){
					if(x==l+1){
						ans=max(ans,cost(l+1,r)+dp[l+1][r]);
					}else if(x==r-1)ans=max(ans,cost(l,r-1)+dp[l][r-1]);
					else ans=max(ans,cost(l,r)+cost(r,x)+dp[l][r]+dp[r][x]);
				}

				dp[l][r]=ans;
			}

		}

		cout<<dp[1][n];
	}

