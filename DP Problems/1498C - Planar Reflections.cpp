
const int N=1e3+1,mod=1e9+7;
int dp[N][N][2];
int n,k;
int rec(int curr,int k,int dir){
	if(k==1)return 1;

	if (dp[curr][k][dir] != -1) {
        return dp[curr][k][dir];
    }

    int ans = 2;  // me and my copy

    if (dir == 1) {
        if (curr < n)
            ans += rec(curr + 1, k, dir) - 1;

        ans %= mod;

        if (curr > 1)
            ans += rec(curr - 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    } else {
        if (curr > 1)
            ans += rec(curr - 1, k, dir) - 1;

        ans %= mod;

        if (curr < n)
            ans += rec(curr + 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    }

    return ans;
}

void solve(){
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	cout<<rec(1,k,1)<<nl;

	
}

