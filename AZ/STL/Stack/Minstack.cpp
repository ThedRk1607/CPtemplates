//with O(1) space
struct minStack{
	int mn=inf;
	stack<int>st;
	void push(int x){
		if(st.empty()){
			st.push(x);
			mn=x;
		}else if(x>=mn){
			st.push(x);
		}else{
			mn=x;
			st.push(2*x-mn);
		}
	}

	void pop(){
		int y=st.top();
		if(y<mn){
			mn=2*mn-y;
		}
		st.pop();
	}

};

void solve(){
 	minStack ds;

 }
