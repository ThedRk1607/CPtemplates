const int MAXLOG=70;


int a, b;
int dp[MAXLOG][2][2][2][2];

int rec(int i, int j, int k, int l, int m)
{
  if (i < 0)
    return (j && k && l && m) ? 1LL : 1LL;
  if (dp[i][j][k][l][m] != -1)
    return dp[i][j][k][l][m];
  int ret = 0;
  int L = a & (1LL << i);
  int R = b & (1LL << i);
  //(0,0)
  if ((j || !L) && (l || !L))
    ret+=rec(i - 1, j, (R) ? 1 : k, l, (R) ? 1 : m);
  //(1,0)
  if ((k || R) && (l || !L))
    ret+=rec(i - 1, (!L) ? 1 : j, k, l, (R) ? 1 : m);
  //(0,1)
  if ((m || R) && (j || !L))
    ret+=rec(i - 1, j, (R) ? 1 : k, (!L) ? 1 : l, m);
  // if((k || R) and (m || R))
  // 	ret+=rec(i-1,(!L) ? 1 : j,k,(!L) ? 1 : l,m);
  return dp[i][j][k][l][m] = ret;
}

void solve(){
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	int N=log2(b);
	cout<<rec(N,0,0,0,0)<<nl;	

}
