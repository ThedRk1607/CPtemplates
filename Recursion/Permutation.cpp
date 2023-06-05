
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
