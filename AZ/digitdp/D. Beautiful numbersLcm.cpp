int a[20],dp[20][N+5][50][2],n,up,id[N+5];


int dfs(int pos,int r,int lcm,bool flag){
	if(pos==0){
		return r%lcm==0;
	}
	if(~dp[pos][r][id[lcm]][flag] and !flag)return dp[pos][r][id[lcm]][flag];
	int ans=0,up=(flag?a[pos]:9);
	for(int i=0;i<=up;i++){
		ans+=dfs(pos-1,(r*10+i)%N,i?(i*lcm)/gcd(i,lcm):lcm,flag&&(i==up));
	}
	return dp[pos][r][id[lcm]][flag]=ans;

}

int calc(int x){
	n=0;
	while(x)a[++n]=x%10,x/=10;
	return dfs(n,0,1,1);
}

void solve(){
	int l,r;cin>>l>>r;
	int ans=calc(r)-calc(l-1);
	cout<<ans<<nl;
}
