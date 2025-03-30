const int N=2e3+5;
int m,d;
string a,b;
int dp[N][2][2][N];
int rec(string &s,int i,int even,int bound,int rem){
	if(i==s.length()){
		if(rem==0)return 1;
		else return 0;
	}
	if(~dp[i][even][bound][rem])return dp[i][even][bound][rem];
	int ans=0;
	int ub=(s[i]-'0');if(bound)ub=9;
	if(even){
		if(bound or d==ub)ans=add(ans,rec(s,i+1,0,bound,(rem*10+d)%m));
		else if(d<ub)ans=add(ans,rec(s,i+1,0,1,(rem*10+d)%m));
	}else{
		for(int di=0;di<=9;di++){
			if(di==d)continue;
			if(bound)ans=add(ans,rec(s,i+1,1,bound,(rem*10+di)%m));
			else if(di<(s[i]-'0'))ans=add(ans,rec(s,i+1,1,1,(rem*10+di)%m));
			else if(di==ub)ans=add(ans,rec(s,i+1,1,0,(rem*10+di)%m));
		}
	}
	return dp[i][even][bound][rem]=ans%mod;

}


void solve(){
	cin>>m>>d>>a>>b;
	memset(dp,-1,sizeof(dp));
	int R=rec(b,0,0,0,0);
	if(a.back()!='0'){
		char d=a.back();a.pop_back();
		d--;a.pb(d);
	}else{
		a.pop_back();
		char d=a.back();a.pop_back();
		d--;a.pb(d);a.pb('9');
	}
	memset(dp,-1,sizeof(dp));
	int L=rec(a,0,0,0,0);
	int ans=sub(R,L);
	cout<<ans;

}


	

