//generate of lenght upto 4;
rep(length,1,4){
		int nm=1;
		rep(j,0,length+1)nm*=26;
		rep(j,0,nm){
			string t;
			int tmp=j;
		rep(k,0,length){
			int d=tmp%26;
			t.pb('a'+d);
			tmp/=26;
		}
		reverse(all(t));
      //check first lex string not appear in s;
		if(s.find(t)==-1){
			cout<<t<<nl;
			return;
		}
		}

	}
	
