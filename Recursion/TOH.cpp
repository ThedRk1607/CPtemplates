
void TOH(int src,int med,int des,int n){
	if(n==1){
		cout<<"Moving ring from src to des "<<src<<" "<<des<<nl;
		return;
	}
  //transfer(n-1) ring from src to med and consider des as med;
	TOH(src,des,med,n-1);
  //transfer remaining one ring to src to des;
	cout<<"Moving ring from src to des "<<src<<" "<<des<<nl;
  //now then transfer rings from med to des and consider med as src and des to des and src as med;
	TOH(med,src,des,n-1);
	return;

}

void solve(){
	int n;cin>>n;
	TOH(1,2,3,n);
}
