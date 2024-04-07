#include<bits/stdc++.h>
using namespace std;


int ans = 0;
vector<int> mp_s(26,0),mp_t(26,0);

void insert(int x){
    ans -= max(0,mp_s[x]-mp_t[x]);
    mp_s[x]++;
    ans += max(0,mp_s[x]-mp_t[x]);
}

void erase(int x){
    ans -= max(0,mp_s[x]-mp_t[x]);
    mp_s[x]--;
    ans += max(0,mp_s[x]-mp_t[x]);
}


int min_changes_needed(vector<int> &mp_s, vector<int> &mp_t){
    for(int i=0;i<26;i++){ // O(26)
        // if(mp_s[i]>mp_t[i]){ // O(log(26))
        //     ans += mp_s[i]-mp_t[i];
        // }
        ans += max(0,mp_s[i]-mp_t[i]);
    }
    return ans;
}

int main()
{
    string s,t;
    cin>>s>>t; //(N)
    
    int n = s.length();
    int m = t.length();
    
    ans = 0;
    
    for(auto v:t){
        mp_t[v-'a']++;
    }
    for(int i=0;i<n;i++){ //O(N)
        // insert 
        mp_s[s[i]-'a']++;
        insert(s[i]-'a');
        // remove
        if(i-m>=0){
            mp_s[s[i-m]-'a']--;
            erase(s[i-m]-'a');
        }
        // check
        if(i>=m-1){
            cout<<ans<<" ";
        }
    }
    cout<<endl;
    
    
    return 0;
}
