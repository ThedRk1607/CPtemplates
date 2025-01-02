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

//digonal for element vise;
 for(int i=1;i<=n;i++){
  	int x1=i,y1=0,x2=0,y2=n-i;
  	int ones=0;
  	for(int j=0;j<n and x1+j<n and y1+j<n;j++)ones+=v[x1+j][y1+j]-'0';
  	for(int j=0;j<n and x2+j<n and y2+j<n;j++)ones+=v[x2+j][y2+j]-'0';
  		amax(mx,ones);

  }
