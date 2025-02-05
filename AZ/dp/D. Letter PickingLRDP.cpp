
 /* For question D:simple o(n^2) solution using min-max We need to observe the fact that since Alice is going first therefore either Alice can win or it will be a draw.
  means Alice wins and 0 means it is a draw. Also remember, (0|1)=1(bitwise or).
  I approached it considering all the possibilities when Alice is at [l,r].
  It can follow with either Alice choosing s[l] or s[r].
   dp[l][r] denotes who will win after considering substring s[l,l+1.....r].
  If Alice chooses s[l] then Bob will choose either s[l+1] or s[r].
  So, dp[l][r]=min((s[l]<s[l+1])|dp[l+2][r],ans3|(s[l]<s[r])).
   The first part of min function denotes the case when Bob chooses s[l+1] and the second part denotes the case when Bob chooses s[r].
   The or operation is there to take the case that Alice has the advantage of going first.
    Similarly, if Alice chooses s[r] then dp[l][r]=min(dp[l|[r-2(s[r]<s[r-1]),dp[l+1]][r-1]|(s[r]<s[l])).*/

void solve(){
	string s;cin>>s;
	int n=s.length();
	vector<vi>dp(n+1,vi(n+1,2));
	function<int(int,int)> rec = [&](int l,int r) {
     	if(l>r)return 0LL;
     	if(dp[l][r]!=2)return dp[l][r];
     	int ans1=rec(l+2,r),ans2=rec(l+1,r-1),ans3=rec(l,r-2),ans4=rec(l+1,r-1);
     	int ans=max(min(ans1|(s[l]<s[l+1]),ans2|(s[l]<s[r])),min(ans3|(s[r]<s[r-1]),ans4|(s[r]<s[l])));
     	return dp[l][r]=ans;
    };
    if(rec(0,n-1))cout<<"Alice\n";
    else cout<<"Draw\n";

}

