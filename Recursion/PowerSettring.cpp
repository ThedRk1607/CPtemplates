
void Set(string ans,string s){
	if(s.empty()){
		cout<<ans;
		cout<<nl;
		return;
	}
	string ans1=ans;
	string ans2=ans+s[0];
	s.erase(s.begin()+0);
	Set(ans1,s);
	Set(ans2,s);
	
}
