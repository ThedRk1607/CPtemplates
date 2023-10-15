vector<int>a={7,6,5,5,4,1};

int Merge(int left,int mid,int right){
	ll cnt=0;
	 int l=left;
	 int r=mid+1;
	 vi tmp;
	 while(l<=mid and r<=right){
	 	if(a[l]<=a[r])tmp.pb(a[l]),l++;
	 	else tmp.pb(a[r]),r++,cnt+=(mid-l+1);
	 }

	 while(l<=mid)tmp.pb(a[l]),l++;
	 while(r<=right)tmp.pb(a[r]),r++;

	 FOR(i,left,right+1)a[i]=tmp[i-left];
	 return cnt;
}

int Sort(int left,int right){
	ll cnt=0;
	if(left>=right)return cnt ;

	int mid=(left+right)/2;
	 cnt+=Sort(left,mid);
	 cnt+=Sort(mid+1,right);
	 cnt+=Merge(left,mid,right);

	 return cnt;
	
}

void solve(){
	Sort(0,5);
	FORR(x,a)cout<<x<<nl;
	
}
