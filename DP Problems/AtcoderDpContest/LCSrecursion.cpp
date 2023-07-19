
string s,t;
int n,m;
int dp[3005][3005];
int rec(int i,int j){
	 if(i==n or j==m)return 0;

	 if(dp[i][j]!=-1)return dp[i][j];

	 int ans=0;
	 ans=max(rec(i,j+1),rec(i+1,j));
	 if(s[i]==t[j]){
	 	 ans=1+rec(i+1,j+1);
	 }

	 return dp[i][j]=ans;


}
string ans;
void printSol(int i,int j){
	if(i==n or j==m)return ;
	if(rec(i,j)==rec(i+1,j))printSol(i+1,j);
	else if(rec(i,j)==rec(i,j+1))printSol(i,j+1);
	else {
		ans.pb(s[i]);
		printSol(i+1,j+1);
	}

}

void solve(){
	cin>>s>>t;
	n=s.size();
	m=t.size();
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0);
	printSol(0,0);
	//cout<<ans<<nl;
}

