
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	vector<int>A;
	rep(i,0,n)A.pb((s[i]-'0')*(i+1));
	int c=0,i=0;
	rep(i,1,n)A[i]+=A[i-1];
	vi ans;
	while(i<n or c>0) {
	   if(i<n)c+=A[n-i-1];
	   ans.pb(c%10);
	   c/=10;
	   i++;
	}
	reverse(all(ans));
	repp(x,ans)cout<<x;
	
	 
}
