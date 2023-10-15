ector<int>a={7,6,5,5,4,1};


void Sort(int left,int right){
	
	if(left>=right)return;
	int l=left,r=right;
	int pivot=a[r];

	while(l<=r){
		while(a[l]<pivot)l++;
		while(a[r]>pivot)r--;

		if(l<=r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}

	Sort(left,r);
	Sort(l,right);

	
}

void solve(){
	Sort(0,5);
	FORR(x,a)cout<<x<<nl;
	
}
