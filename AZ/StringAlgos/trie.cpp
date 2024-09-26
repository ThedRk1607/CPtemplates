const int N=1e5+5;
int trie[N][26];
vector<bool>stop(N,0);
vector<bool>win(N,0),lose(N,0);
int node_cnt;
//insert 
void insert(string words){
	int node=0;
	for(auto w:words){
		if(trie[node][w-'a']==0)trie[node][w-'a']=++node_cnt;
		node=trie[node][w-'a'];
	}
	stop[node]=1;
}
//then use dfs
void dfs(int node){
	// win[node]=lose[node]=false;
	// bool isLeaf=true;
	for(int i=0;i<26;i++){
		if(trie[node][i]==0)continue;
		//isLeaf=false;
		dfs(trie[node][i]);
		// win[node]  = win[node]|(1 - win[trie[node][i]]);
		// lose[node]  = lose[node]|(1 - lose[trie[node][i]]);
	}
}
