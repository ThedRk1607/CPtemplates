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



//prefix tree based trie
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define the maximum number of possible characters (lowercase English letters)
const int ALPHABET_SIZE = 26;

// Trie Node Structure
struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    int count; // Count of strings passing through this node

    TrieNode() : count(0) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
    }
};

// Trie Class
class Trie {
private:
    TrieNode* root;
    
    // Insert a string into the trie
    void insert(const string& s) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->count++; // Increment the count of strings passing through this node
        }
    }

void remove(const string& s,Trie*root,int k) {
        Trie* node = root;int len=0;
        for (char c : s) {len++;
            int idx = c - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new Trie();
            }
            node = node->child[idx];
            node->count--; // Increment the count of strings passing through this node
            if(node->count==k-1){
                mp[len]--;
                if(mp[len]==0)st.erase(len);
            }
        }
    }



    // Find LCP for a given string with the rest of the strings in the Trie
    int findLCP(const string& s) {
        TrieNode* node = root;
        int lcp = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx] || node->children[idx]->count == 1) {
                break;
            }
            node = node->children[idx];
            lcp++;
        }
        return lcp;
    }
};

