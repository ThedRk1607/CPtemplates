for(int i=0;i<n;i++){
		if(i&1){
			for(int j=0;j<m;j++){
				if(v[i][j]=='R')now++;
				if(now>w)now=((--w1)<0),x++;
				v[i][j]=ch[x];
			}
		}else{
			for(int j=m-1;j>=0;j--){
				if(v[i][j]=='R')now++;
				if(now>w)now=((--w1)<0),x++;
				v[i][j]=ch[x];
			}
		}
	}
