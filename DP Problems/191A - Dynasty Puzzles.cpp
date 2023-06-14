
// d[i][j], i is the first character in the name of the dynasty, j is the last current character. d [ i ][ j ] is the maximum current length.
//Transition: For a word with first letter l , last letter r and length s for all possible first letters i, 
//the state d [ i ][ r ] can be improved by the value d [ i ][ l ] +  s .
//The answer will be the maximum value of d [ i ][ i ] for all i .

int dp[26][26];

void solve(){
	int n;cin>>n;
	ZERO(dp);
	for(int j=1;j<=n;j++){
		string str;cin>>str;
		int len=str.size();
		int s=str[0]-'a';
		int e=str[len-1]-'a';

		for(int i=0;i<26;i++){
			if(dp[i][s]){
				dp[i][e]=max(dp[i][e],dp[i][s]+len);
			}
		}
		dp[s][e]=max(dp[s][e],len);
	}

	int ans=0;
	for(int i=0;i<26;i++)amax(ans,dp[i][i]);
		cout<<ans<<nl;

}
