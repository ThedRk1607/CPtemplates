void solve(){
		int n;
		cin >> n;
		vector<int> a(n + 1), inDeg(n + 1, 0);
 
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			inDeg[a[i]]++;
		}
 
		vector<int> q;
		for(int i = 1; i <= n; i++) {
			if(inDeg[i] == 0)
				q.push_back(i);
		}
		int y=2;
		while(!q.empty()){
			y++; vi nq;
			for(auto ch:q){
				if(--inDeg[a[ch]]==0)nq.pb(a[ch]);
			}	
			q=nq;
		}
		cout<<y<<nl;

}
