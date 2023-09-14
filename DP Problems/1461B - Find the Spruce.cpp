
char a[507][507];
int sum[507][507];

void solve(){
	int n,m;cin>>n>>m;
	FOR(i,1,n+1)FOR(j,1,m+1)cin>>a[i][j];
	ZERO(sum);
	int ans=0;
	for(int i=n;i>=1;i--){
		FOR(j,1,m+1){
			if(a[i][j]!='*')continue;
			ans++;
			sum[i][j]=1;
			if(i+1>n or j-1<1 or j+1>m)continue;
			int mn=1e8;
			for(int k=j-1;k<=j+1;k++){
				amin(mn,sum[i+1][k]);
			}
			sum[i][j]+=mn;
			ans+=mn;
		}
	}
	cout<<ans<<nl;
	
}

		
