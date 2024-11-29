int g[101][101];

void f(int n, vector<vector<int>>& grid){
	int val=n*n;
	int top=0,bottom=n-1,left=0,right=n-1;
	while(top<=bottom and left<=right){
		for(int i=left;i<=right;i++)grid[top][i]=val--;
		top++;
		for(int i=top;i<=bottom;i++)grid[i][right]=val--;
		right--;
		if(top<=bottom){
			for(int i=right;i>=left;i--)grid[bottom][i]=val--;
			bottom--;
		}
		if(left<=right){
			for(int i=bottom;i>=top;i--)grid[i][left]=val--;
			left++;
		}
	}
}
