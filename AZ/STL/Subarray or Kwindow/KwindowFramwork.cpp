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

//using monotone deque;
struct monotone_deque{
	deque<int>dq;
	void insert(int x){
		while(!dq.empty() and dq.back()>x)dq.pop_back();
		dq.pb(x);
	}

	void erase(int x){
		if(dq.front()==x)dq.pop_front();
	}
	int getmin(){
		return dq.front();
	}
};
//problem using monotone deque both side div2-902-D
void solve(){
   int n;cin>>n;
   vi a(n);repp(x,a)cin>>x;
   vi b(n);repp(x,b)cin>>x;
   for(int i=0;i<n;i++)if(b[i]<a[i]){cout<<"NO\n";return;}
   deque<int>dq;
   auto f=[&](int x){
      while(dq.size() and dq.back()<=a[x])dq.pop_back();
      while(dq.size() and dq.front()>b[x])dq.pop_front();
      dq.pb(a[x]);
      if(dq.front()==b[x])a[x]=b[x];
   };
   rep(i,0,n)f(i);
   for(int i=n-1;i>=0;i--){
      f(i);if(a[i]!=b[i]){cout<<"NO\n";return;}
   }
   cout<<"YES\n";

}
