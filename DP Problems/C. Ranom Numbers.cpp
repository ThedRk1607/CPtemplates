
int dp[2<<17][6][2];
string s;
ll val[]={1,10,100,1000,10000};

int rec(int i,int mx,int ch){
if(i==-1)return 0;
if(dp[i][mx][ch]!=-1)return dp[i][mx][ch];
	int sign=1;
	if(s[i]-'A'<mx)sign=-1;
	ll res=sign*val[s[i]-'A']+rec(i-1,max(mx,int(s[i]-'A')),ch);
	if(!ch){
		for(int i=0;i<5;i++){
			if(i!=s[i]-'A'){
				sign=1;
				if(i<mx)sign=-1;
				amax(res,sign*val[i]+rec(i-1,max(mx,i),1));
			}
		}
	}
	return dp[i][mx][ch]=res;
}
 
	void solve(){
	  cin>>s;
	  memset(dp,-1,sizeof(dp));
	  int n=s.size();
	  //reverse(all(s));
	  cout<<rec(n-1,0,0)<<nl;
	}
