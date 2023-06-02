
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

void Insert(stack<int> &v,int last){
	if(v.size()==0 or v.top()<=last){
		v.push(last);
		return ;
	}

	int val=v.top();
	v.pop();
	Insert(v,last);
	v.push(val);
	
	
}
//sorting a stack using recursion;
void Sort(stack<int> &v){
	if(v.size()==1)return ;

	int last=v.top();
	v.pop();
	Sort(v);
	Insert(v,last);
	
}

void display(stack<int>&s){
	if(s.size()==0)return;

	int x=s.top();
	s.pop();
	display(s);
	cout<<x<<" ";
}
