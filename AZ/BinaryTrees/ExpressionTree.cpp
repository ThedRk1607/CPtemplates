//expresion tree evaluation
int evalTree(node*cur){
		if(cur->type==op){
			int lval=evalTree(cur->left);
			int rval=evalTree(cur->right);
			return handleCase(cur->type,lval,rval);
		}else{
			return cur->val;
		}
	}

//expresion tree from postfix
	node*ExpressionTree(vector<string>postFix){
		stack<node*>st;
		for(auto val:postFix){
			if(isOp(val)){
				node*tmp=new node(val,op);
				tmp->right=st.top();st.pop();
				tmp->left=st.top();st.pop();
				st.push(tmp);
			}else{
				node*tmp=new node(val,op);
				st.push(tmp);
			}
		}
		return st.top();
	}

	//postfix to finalValue
	node*ExpressionTree(vector<string>postFix){
		stack<node*>st;
		for(auto val:postFix){
			if(isOp(val)){
				int lval=st.top();st.pop();
				int rval=st.top();st.pop();
				st.push(handlecase(val,lval,rval));
			}else{
				st.push(stoi(val));
			}
		}
		return st.top();
	}
	
