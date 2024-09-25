void solve(){
	 int n;cin>>n;
    string s; cin>>s;

    int kmp[n+1]; //Pi array
    int i=0, j=-1;
    kmp[0]=-1;
    while(i < n){
        while(j != -1 && s[i] != s[j]) j=kmp[j];
        j++;i++;
        kmp[i]=j;
    }

	// if (kmp[n]==0) {
 //        cout<<-1<<endl;
 //        return;
 //    }
 //    for (int i=2; i < n; i++){
 //        if (kmp[i] == kmp[n]){
 //            cout<<s.substr(0, kmp[i])<<endl;
 //            return;
 //        }
 //    }

 //    if (kmp[kmp[n]]==0){
 //        cout<<-1<<endl;
 //        return;
 //    }

 //    cout<<s.substr(0, kmp[kmp[n]])<<endl;

}
