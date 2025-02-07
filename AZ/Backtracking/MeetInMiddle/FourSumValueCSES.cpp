void solve(){
  int n,x;cin>>n>>x;
  vi v(n);repp(x,v)cin>>x;

  map<int,vii>mp;
  for(int i=0;i<n;i++){
  	for(int j=i+1;j<n;j++){
  		if(mp[x-v[i]-v[j]].size()){
  			auto it=mp[x-v[i]-v[j]][0];
  			cout<<it.F+1<<" "<<it.S+1<<" "<<i+1<<" "<<j+1<<nl;
  			return;
  		}
  	}
   for(int j=0;j<i;j++){
   	 mp[v[j]+v[i]].pb({j,i});
   }
  }
  cout<<"IMPOSSIBLE\n";

}
