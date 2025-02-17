//G. A/B Matrix div3-644
void solve(){
  int n,m,a,b;cin>>n>>m>>a>>b;
  if(n*a!=m*b){
  	cout<<"NO\n";return;
  }
  cout<<"YES\n";
  vector<string>v;
  rep(i,0,n){
  	v.pb(string(m,'0'));
  }
  int d=0;
  for(d=1;d<m;d++){
  	if((d*n)%m==0)break; //find shift
  }

  int i=0,j=0;
  while(i<n){
  	for(int k=0;k<a;k++)v[i][(k+j)%m]='1';
  	j+=d;
  	i++;
  }

 repp(x,v)cout<<x<<nl;
