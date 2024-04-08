//check balance
void solve(){
  	string s;cin>>s;
  	map<char,int>mp;
  	mp['(']=+1;
  	mp['{']=+2;
  	mp['[']=+3;
  	mp[')']=-1;
  	mp['}']=-2;
  	mp[']']=-3;
  	stack<int>st;
  	repp(x,s){
  		int val=mp[x];
  		if(val>0)st.push(val);
  		else{
  			if(!st.empty() and st.top()+val==0)st.pop();
  			else{
  				cout<<"0\n";
  				return;
  			}
  		}
  	}
  	if(!st.empty()){
  		cout<<"0\n";
  		return;
  	}
  	cout<<"1\n";

   }
//min paren required to make it balance;

 void solve(){
  	string s;cin>>s;
  	map<char,int>mp;
  	mp['(']=+1;
  	mp['{']=+2;
  	mp['[']=+3;
  	mp[')']=-1;
  	mp['}']=-2;
  	mp[']']=-3;
  	stack<int>st;
  	int mn=0;
  	repp(x,s){
  		int val=mp[x];
  		if(val>0)st.push(val);
  		else{
  			if(!st.empty() and st.top()+val==0)st.pop();
  			else{
  				mn++;
  			}
  		}
  	}
  
  	mn+=st.size();
  	cout<<mn<<nl;

   }
