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

void solve(){
 	int n,k;cin>>n>>k;
 	vi v(n);repp(x,v)cin>>x;
 	monotone+deque ms;
 	rep(i,0,n){
 		ms.insert(v[i]);
 		if(i-k>=0)ms.erase(ms.find(v[i]));
 		if(ms.size()==k)cout<<(*ms.begin())<<nl;
 	} 
  }
