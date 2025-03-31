const int N=16;



int dp[N][2][170];

int rec(string &s,int i, int bound,int sum)
{
	if(i==s.length())return sum;
	if(~dp[i][bound][sum])return dp[i][bound][sum];
  int res=0;
  int lim=(bound==1)?(s[i]-'0'):9;
  for(int d=0;d<=lim;d++){
  	res+=rec(s,i+1,(bound==1)&&(d==(s[i]-'0')),sum+d);
  }
  return dp[i][bound][sum]=res;
}

void solve(){
	string s,t;cin>>s>>t;
	memset(dp,-1,sizeof(dp));
	int R=rec(t,0,1,0);
	if(s!="0"){
		if(s.back()!='0'){
			char ch=s.back();s.pop_back();ch--;s.pb(ch);
		}else{
			s.pop_back();char ch=s.back();s.pop_back();ch--;s.pb(ch);s.pb('9');
		}
	}
	memset(dp,-1,sizeof(dp));
	int L=rec(s,0,1,0);
	cout<<R-L<<nl;


}

