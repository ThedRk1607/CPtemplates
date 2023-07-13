

int dp[100][5];
string t="1101";
int n; 
//1-{},2-{1},3-{11},4-{110},5-{1101};
//dp[i][j] #substring in which t as subsequence not appears;

int rec(int level,int match){
	//pruning
	if(match==4)return 0;

	//base case
	if(level==n)return 1;

	//cache
	if(dp[level][match]!=-1)return dp[level][match];

	int ans=rec(level+1,match+1)+rec(level+1,match);
	cout<<ans<<nl;
	return dp[level][match]=ans;
}

void solve(){
	cin>>n;
	memset(dp,-1,sizeof(dp));
	//rec(0,0);
}

