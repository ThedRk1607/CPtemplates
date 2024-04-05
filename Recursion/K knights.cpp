//method 1
int ans,n,k;
int board[14][14];

int dx[]={-2,-2,2,2,1,-1,1,-1};
int dy[]={1,-1,1,-1,-2,-2,2,2};

bool check(int i,int j){
	if(board[i][j]==1)return 0;
	rep(r,0,8){
		int x=i+dx[r];
		int y=j+dy[r];
		if(x<n and x>=0 and y>=0 and y<n and board[x][y]==1)return 0;
	}
	return 1;
}
 void rec(int level,int lastx,int lasty){
 	if(level==k){
 		ans++;
 		return;
 	}
 	for(int i=lastx;i<n;i++){
 		for(int j=0;j<n;j++){
 			if(i==lastx and j<=lasty)continue;
 			if(check(i,j)){
 				board[i][j]=1;
 				rec(level+1,i,j);
 				board[i][j]=0;
 			}
 		}
 	}
 }


void solve(){
  n=2,k=3;
	rec(0,0,-1);
	cout<<ans<<nl;
	
}

//method2
int ans,n,k;
int board[14][14];

int dx[]={-2,-2,2,2,1,-1,1,-1};
int dy[]={1,-1,1,-1,-2,-2,2,2};

bool check(int i,int j){
	if(board[i][j]==1)return 0;
	rep(r,0,8){
		int x=i+dx[r];
		int y=j+dy[r];
		if(x<n and x>=0 and y>=0 and y<n and board[x][y]==1)return 0;
	}
	return 1;
}
 void rec(int level,int knights){
 	if(level==n*n){
 		if(knights==0)ans++;
 		return;
 	}
 	//dont take knight;
 	rec(level+1,knights);
 	//take knight;
 	int row=level/n;
 	int col=level%n;
 	if(check(row,col)){
 		board[row][col]=1;
 		rec(level+1,knights-1);
 		board[row][col]=0;
 	}
 	
 }


void solve(){
  n=2,k=2;
	rec(0,k);
	cout<<ans<<nl;
	
}
