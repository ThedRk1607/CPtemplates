void solve(){
  int n,md;cin>>n>>md;
  vi v(n);repp(x,v)cin>>x;
  vi sub1,sub2;
  int m=n/2;
  for(int i=0;i<(1<<m);i++){
  	int sum=0;
  	for(int j=0;j<m;j++){
  		if((i>>j)&1)sum+=v[j];
  	}
  sub1.pb(sum%md);
  }
  sort(all(sub1));
  int k=n-m,ans=0;
  reverse(all(v));
   for(int i=0;i<(1<<k);i++){
  	int sum=0;
  	for(int j=0;j<k;j++){
  		if((i>>j)&1)sum+=v[j];
  	}
  	sub2.pb(sum%md);	
  }

 sort(all(sub2));
  repp(x,sub1){
  	auto it=lb(all(sub2),md-x);
  	if(it==sub2.begin())continue;
  	it--;
  	amax(ans,x+(*it));
  }
  cout<<ans<<nl;

  
}
