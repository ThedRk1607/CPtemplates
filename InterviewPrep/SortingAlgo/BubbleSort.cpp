void solve(){
	int n;cin>>n;
	vi v(n);FORR(x,v)cin>>x;
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int i=1;i<n;i++){
			if(v[i-1]>v[i])swap(v[i-1],v[i]),cnt++;
		}
	}
	FORR(x,v)cout<<x<<" ";
	cout<<nl<<cnt;
}
