//	A - Coin game

void solve(){
	int x,y,a,b;cin>>x>>y>>a>>b;
	vector<pii>ans;
	for(int i=a;i<=x;i++){
		for(int j=b;j<=y;j++){
			if(i>j)ans.pb({i,j});
		}
	}

	cout<<ans.size()<<nl;
	FORR(x,ans)cout<<x.F<<" "<<x.S<<nl;

}
