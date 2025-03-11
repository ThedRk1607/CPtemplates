void solve(){
  int n,k;cin>>n>>k;
  vi p,perm;
  if(n>12){
  	for(int i=1;i<=n;i++){
  		if(i>=n-12)p.pb(i);
  		else perm.pb(i);
  	}
  }else {
  	for(int i=1;i<=n;i++)p.pb(i);
  }

  int fact=1;
  rep(i,1,p.size())fact=fact*i; //arrange n-1 elements;
   k=k-1;//0-based indexing;
  while(perm.size()<n){
  	perm.pb(p[k/fact]);
  	p.erase(p.begin()+k/fact);
  	if(p.size()==0)break;
  	k%=fact;
  	fact/=p.size();
  }

  repp(x,perm)cout<<x<<" ";

}




	
