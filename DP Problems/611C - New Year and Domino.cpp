const int N=505;
int vdp[N][N],hdp[N][N];

void solve(){
	int h,w;cin>>h>>w;
	char grid[h][w];
	FOR(i,0,h)FOR(j,0,w)cin>>grid[i][j];

	for(int i=0;i<h;i++){
		int cnt=0;
		for(int j=1;j<w;j++){
			if(grid[i][j]=='.' and grid[i][j-1]=='.')cnt++;
			hdp[i][j]=cnt;
		}
	}

	for(int i=0;i<w;i++){
		int cnt=0;
		for(int j=1;j<h;j++){
			if(grid[j][i]=='.' and grid[j-1][i]=='.')cnt++;
			vdp[j][i]=cnt;
		}

	}
	



	int q;cin>>q;
	while(q--){
		int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
		int ans=0;
		FOR(i,r1-1,r2)ans+=hdp[i][c2-1]-hdp[i][c1-1];
		FOR(i,c1-1,c2)ans+=vdp[r2-1][i]-vdp[r1-1][i];

		cout<<ans<<nl;
	}

}

