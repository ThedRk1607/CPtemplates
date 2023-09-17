
ll grid[1005][1005],a[1005][1005];
void solve(){
	ll n,q;cin>>n>>q;
	ZERO(grid);
	ZERO(a);
	FOR(i,0,n){
		ll h,w;cin>>h>>w;
		a[h][w]+=h*w;
	}
for(int i=1;i<=1000;i++){
	for(int j=1;j<=1000;j++){
		grid[i][j]=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1]+a[i][j];
	}
}

	FOR(i,0,q){
		ll hs,ws,hb,wb;cin>>hs>>ws>>hb>>wb;
		ll ans=grid[hb-1][wb-1]-grid[hb-1][ws]-grid[hs][wb-1]+grid[hs][ws];
		
		cout<<ans<<nl;
	}


}
