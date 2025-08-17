function<int(vi&,int,int)>in=[&](vi &a,int l,int r){
		if(l==r)return 0LL;
		int mid=(l+r)/2;
		int L=in(a,l,mid);
		int R=in(a,mid+1,r);
		vi tmp;
		int x=l,y=mid+1,c=0;
		while(x<=mid and y<=r){
			if(a[x]<=a[y]){tmp.pb(a[x++]);}
			else{
				tmp.pb(a[y++]);c+=(mid-x+1);
			}
		}
		while(x<=mid){
			tmp.pb(a[x]);x++;
		}
		while(y<=r){
			tmp.pb(a[y]);y++;
		}
		for(int i=l;i<=r;i++)a[i]=tmp[i-l];
		return L+R+c;

	};
