const int N=1005;
char grid[N][N];
vector<int>in_row[N],in_col[N];
bool vis[N][N];
int n,m;

void check(vector<int>&v){
	FOR(i,1,v.size()){
		if(v[i]!=v[i-1]+1){
			cout<<"-1\n";
			exit(0);
		}
	}
}

void dfs(int i,int j){
	vis[i][j]=1;
	for(int r=0;r<4;r++){
		int x=i+dx[r];
		int y=j+dy[r];
		if((x>=0 and x<n) and (y>=0 and y<m) and grid[x][y]=='#' and !vis[x][y]){
			dfs(x,y);
		}
	}
}

void solve(){
	cin>>n>>m;
	for(int row=0;row<n;row++){
		for(int col=0;col<m;col++){
			cin>>grid[row][col];
			if(grid[row][col]=='#'){
				in_row[row].pb(col);
				in_col[col].pb(row);
			}

		}
	}
	int rows=0,cols=0;
	
	for(int row=0;row<n;row++){
		check(in_row[row]);
		if(!in_row[row].empty())rows++;

	}
	for(int col=0;col<m;col++){
		check(in_col[col]);
		if(!in_col[col].empty())cols++;
	}

	if((rows==n)!=(cols==m)){
		cout<<"-1\n";
		return;
	}
int ans=0;
ZERO(vis);
	for(int row=0;row<n;row++){
		for(int col=0;col<m;col++){
			if(grid[row][col]=='#' and !vis[row][col]){
				ans++;
				dfs(row,col);
			}
		}
	}

cout<<ans<<nl;

}


