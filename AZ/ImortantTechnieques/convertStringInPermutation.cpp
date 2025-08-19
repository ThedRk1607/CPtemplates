string s;cin>>s;
	string t=s;reverse(all(t));
	map<int,vi>a,b;
	rep(i,0,n){a[s[i]-'a'].pb(i);b[t[i]-'a'].pb(i);}
	vi p(n);
	rep(i,0,26){
		if(a[i].empty())continue;
		rep(j,0,a[i].size())p[a[i][j]]=b[i][j];
	}
