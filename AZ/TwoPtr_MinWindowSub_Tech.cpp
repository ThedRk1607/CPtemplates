void solve(){
	string s,t;cin>>s>>t;
	int n=s.length(),m=t.length();
	map<char,int>tfreq;
	repp(x,t)tfreq[x]++;

	map<char,int>windowfreq;
		auto check=[&](char ch){
			repp(x,tfreq){
				if(x.F==ch){
					if(windowfreq[ch]+1<x.S)return false;
				}else {
					if(windowfreq[x.F]<x.S)return false;
				}
			}
			return true;
		};

	int tail=0,head=-1;
	int idx=-1;
	int mn=inf;
	while(tail<n){
		while(head+1<n and !check(s[head+1])){
			head++;
			windowfreq[s[head]]++;
		}

		int len=(head-tail+1);
		if(head+1<n and mn>len){
			mn=len+1;
			idx=tail;
		}


		if(tail<=head){
			windowfreq[s[tail]]--;
			tail++;
		}else{
			tail++;
			head=tail-1;
		}
	}
	//cout<<idx<<nl;
	   if(idx==-1)cout<<"";
		else cout<<s.substr(idx,mn+1);

}
