const int N=5e3+5,mod=1e9+7;

vector<vector<int> >dp(N,vector<int>(N));


void solve(){
	int n,m;cin>>n>>m;
	int grid[n+1][m+1];

	FOR(i,0,n)FOR(j,0,m){
		char c;cin>>c;
		grid[j][i]=c-'0';

	}
	
	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			if(grid[i][j])grid[i][j]+=grid[j-1][i];
		}
	}
int ans=0;
	for(int i=0;i<m;i++){
		sort(grid[i],grid[i]+n);
		for(int j=0;j<n;j++){
			amax(ans,grid[i][j]*(n-j));
		}
	}
	cout<<ans<<nl;


}
