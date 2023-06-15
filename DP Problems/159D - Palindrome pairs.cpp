
ll dp[2010];
ll start[2010];
bool pal[2010][2010];
string str;

void ispal(){
	for(int i=0;i<str.length();i++){
		pal[i][i]=1;
		pal[i][i+1]=(str[i]==str[i+1]);
	}
	pal[str.length()-1][str.length()-1]=1;

	for(int j=2;j<str.length();j++){
		for(int i=0;j+i<str.length();i++){
			pal[i][i+j]=pal[i+1][j+i-1] && str[i]==str[i+j];
		}
	}

	for(int i=0;i<str.length();i++){
		for(int j=i;j<str.length();j++){
			start[i]+=pal[i][j];
		}
	}
}

void solve(){
	ZERO(dp);
	ZERO(start);
	cin>>str;

	ispal();
	dp[str.length()-1]=1;
	for(int i=str.length()-2;i>=0;i--){
		dp[i]=dp[i+1]+start[i];
	}
ll ans=0;
for(int i=0;i<str.length();i++){
	for(int j=i;j<str.length();j++){
		if(pal[i][j])ans+=dp[j+1];
	}
}

cout<<ans<<nl;
  
}
