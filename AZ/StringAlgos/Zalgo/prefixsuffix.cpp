void solve(){
	string s;cin>>s;
	int n=s.length();
	vi z=z_function(s);
	z[0]=n;
	vii res;
	vi nz=z;sort(all(nz));
	for(int i=0;i<n;i++){
		if(z[n-i-1]!=i+1)continue;
		int cnt=nz.end()-lb(all(nz),i+1);
		res.pb({i+1,cnt});
	}
	cout<<res.size()<<nl;
	repp(x,res)cout<<x.F<<" "<<x.S<<nl;
}
	
