
void solve(){
	int n;cin>>n;

	vi v(n-1);FORR(x,v)cin>>x;
      vi ans;

	ans.pb(v[0]);
	for(int i=1;i<n-1;i++)ans.pb(min(v[i],v[i-1]));
		ans.pb(v[n-2]);

FORR(x,ans)cout<<x<<" ";
cout<<nl;

}
