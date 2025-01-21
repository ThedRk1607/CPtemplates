void solve(){
	int n,m;cin>>n>>m;
	mod=m;
	vector<vi>g(n+1);
	rep(i,0,n-1){
		int u,v;cin>>u>>v;u--,v--;
		g[u].pb(v);g[v].pb(u);
	}
	vi indp(n+1,1),outdp(n+1,1);
	function<void(int,int,int)>dfs1=[&](int node,int p,int c){
		indp[node]=1; //paint black
		for(auto ch:g[node]){
			if(ch==p)continue;
			dfs1(ch,node,c);
			indp[node]=mul(indp[node],indp[ch]);
		}
		indp[node]++;//paint white
		
	};
	
	function<void(int,int)>dfs2=[&](int node,int p){

		//prefix prod;
		int pre=1;
		for(auto ch:g[node]){
			if(ch==p)continue;
			outdp[ch]=mul(outdp[ch],pre);
			pre=mul(pre,indp[ch]);
			
		}
		//suffix prod;
		reverse(all(g[node]));
		int suf=1;
		for(auto ch:g[node]){
			if(ch==p)continue;
			outdp[ch]=mul(outdp[ch],suf);
			suf=mul(suf,indp[ch]);
			
		}

		for(auto ch:g[node]){
			if(ch==p)continue;
			outdp[ch]=mul(outdp[ch],outdp[node]);
			outdp[ch]++;
			dfs2(ch,node);
			
			
		}
		

	};
	dfs1(0,-1,1);
	dfs2(0,-1);
	rep(i,0,n)cout<<mul(outdp[i],sub(indp[i],1))<<nl;
	
	


}
