//how to find diagonal of every element
vector<vector<int>>v(n,vector<int>(n));
	rep(i,0,n)rep(j,0,n)cin>>v[i][j];
	vi ans(2*n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int d=i-j+n-1;// d is diagonal of (i,j) element
			ans[d]=max(ans[d],-v[i][j]);//max of all diagonals elements;
		}
	}
