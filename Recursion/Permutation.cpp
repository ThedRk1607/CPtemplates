
vi perm;
int n;
bool chosen[100];
void search(){
	if(perm.size()==n){
		FORR(x,perm)cout<<x+1<<" ";
		cout<<nl;
		return;
	}

	for(int i=0;i<n;i++){
		if(chosen[i])continue;
		chosen[i]=true;
		perm.pb(i);
		search();
		chosen[i]=false;
		perm.pop_back();
	}
}


//
count permutations;
int rec(string a,string b){
	
	if(b.size()==0){
		return 1;
	}

	 int cnt=0;
	for(int i=0;i<=a.size();i++){
		cnt+=rec(a.substr(0,i)+b[0]+a.substr(i),b.substr(1));
	}
	return cnt;
}
