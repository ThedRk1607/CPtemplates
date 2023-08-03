
void solve(){
	int n;cin>>n;
	
	stack<int>st;

	for(int i=0;i<n;i++){
			int t;cin>>t;
			if(st.empty()){
				st.push(t);
				continue;
			}

			if(t>st.top())st.push(t);
			else {
				int tt=st.top();
				while(!st.empty() and st.top()>t)st.pop();
				st.push(tt);
			}
	}
cout<<st.size()<<nl;

}
//alternate solution;
void solve(){
	int n;cin>>n;
	
	int cnt(0),mx(0);
	for(int i=1;i<=n;i++){
		ll x;cin>>x;
		amax(mx,x);
		cnt+=(mx==i);
	}
	cout<<cnt<<nl;

}
