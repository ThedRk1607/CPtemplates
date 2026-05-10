int grid[3005][3005];
int n;



void solve(){
  cin>>n;
  vector<vector<char>>g(n,vector<char>(n));
  rep(i,0,n)rep(j,0,n)cin>>g[i][j];
  vector<vector<char>>r(n,vector<char>(n));
  rep(i,0,n)rep(j,0,n){
    int d=min({i+1,j+1,n-i,n-j});
    int x=i,y=j;d%=4;while(d>0){int nx=y,ny=n-x-1;x=nx;y=ny;d--;}
    r[x][y]=g[i][j];

  }
  rep(i,0,n){rep(j,0,n)cout<<r[i][j];cout<<nl;}

}

