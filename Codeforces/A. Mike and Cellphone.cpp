void solve(){
	int n;cin>>n;
	 string s;cin>>s;
	 map<int,int>mp;
	 FORR(x,s)mp[x-'0']++;
	 bool a=false,s1=false,d=false,f=false;
	 if(mp[1] or mp[4] or mp[7] or mp[0])a=true;
	 if(mp[1] or mp[2] or mp[3])s1=true;
	 if(mp[3] or mp[6] or mp[9] or mp[0])d=true;
	 if(mp[7] or mp[0] or mp[9])f=true;

	 if(a and s1 and d and f)cout<<"YES\n";
	 else cout<<"NO\n";


}

 
