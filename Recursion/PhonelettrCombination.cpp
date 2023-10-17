void print(string a,string b){
	if(b.size()==0){
		cout<<a<<nl;
		return;
	}
		int x=b[0]-'0';
	for(int i=(x-1)*3;i<x*3;i++){
	    if(i>25)continue;
		char ch=(i+'a');
		print(a+ch,b.substr(1));
	}
}

void solve(){
	print("","189");


}
