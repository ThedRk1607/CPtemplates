
const int m=(int)1e9+7;
bool grid[8][8];

int cnt2[8][8];

void solve(){
 	string a,b;cin>>a>>b;
 	FOR(i,0,8)FOR(j,0,8)grid[i][j]=true,cnt2[i][j]=-1;

 	queue<pair<int,int>>q;
 	q.push({a[0]-'a',a[1]-'1'});
 	q.push({-1,-1});
 	int cnt=0;
 	
 	
 	while(!q.empty()){
 		auto x=q.front();
 		q.pop();
 		if(x==mpp(b[0]-'a',b[1]-'1'))break;
 		if(x==mpp(-1,-1)){
 			cnt++;
 			q.push(x);
 			continue;
 		}

 		int i=x.F;
 		int j=x.S;
 		int dxx[]={i-1,i-2,i-2,i-1,i+1,i+2,i+2,i+1};
 		int dyy[]={j-2,j-1,j+1,j+2,j+2,j+1,j-1,j-2};

 		for(int i=0;i<8;i++){
 			int x1=dxx[i];
 			int y1=dyy[i];
 			if((x1>=0 and x1<8) and (y1>=0 and y1<8) and grid[x1][y1]){
 				q.push(mpp(x1,y1));
 				grid[x1][y1]=false;
 				cnt2[x1][y1]=1+cnt2[x.F][x.S];
 			}
 		}

 	}

cout<<cnt2[b[0]-'a'][b[1]-'1']+1<<nl;
//cout<<cnt<<nl;
