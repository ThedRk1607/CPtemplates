//to find min in k window

 void solve(){
 	int n,k;cin>>n>>k;
 	vi v(n);repp(x,v)cin>>x;
 	multiset<int>ms;
 	rep(i,0,n){
 		ms.insert(v[i]);
 		if(i-k>=0)ms.erase(ms.find(v[i]));
 		if(ms.size()==k)cout<<(*ms.begin())<<nl;
 	} 
  }

