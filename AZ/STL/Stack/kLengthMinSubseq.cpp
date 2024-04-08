 void solve(){
  	string s;cin>>s;
  	int k,n=s.length();
  	cin>>k;
  	vector<char>v;
  	rep(i,0,n){
  		while(!v.empty() and (s[i]<v.back() and (v.size()+(n-1)-i)>=k))v.pop_back();//check can we delete or not by using size of remaing element;
  		v.pb(s[i]);
  	}
  	rep(i,0,k)cout<<v[i]<<" ";
  	cout<<nl;
   }
