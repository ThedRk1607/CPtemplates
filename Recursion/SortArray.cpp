
void Insert(vi &v,int last){
	if(v.size()==0 or v.back()<=last){
		v.pb(last);
		return ;
	}

	int val=v.back();
	v.pop_back();
	Insert(v,last);
	v.pb(val);
	
}

void Sort(vi &v){
	if(v.size()==1)return ;

	int last=v.back();
	v.pop_back();
	Sort(v);
	Insert(v,last);
}

