//Find the number of Palindromes
#include<bits/stdc++.h>
using namespace std;
 
struct hasher{
    int n, _k, _p;
    vector<int> powk,base,rev;
    
    void init(string s,int k,int p){
        _k = k, _p = p;
        n = s.length();
        powk.resize(n+1);
        base.resize(n+1);
        
        // precompute
        base[0] = 0;
        powk[0] = 1;
        for(int i=0;i<n;i++){
            int num = (s[i]-'a'+1 )%p;
            base[i+1] = (1LL *base[i] * k + num)%p;
            powk[i+1] = (1LL* k * powk[i]) %p;
        }
        
        // reverse
        rev.resize(n+1);
        rev[n] = 0;
        for(int i=n-1;i>=0;i--){
            int num = (s[i]-'a'+1 )%p;
            rev[i] = (1LL *rev[i+1] * k + num)%p;
        }
    }  
    int gethash(int l,int r){ // 0 index
        int ans = (base[r+1] - 1LL *base[l]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
    // reverse hash
    int getrevhash(int l,int r){
        int ans = (rev[l] - 1LL *rev[r+1]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
};
 
 
struct double_hash{
    string temp;
    hasher a,b;
    void init(string s){
        temp = s;
        a.init(s,37,1000000021);
        b.init(s,39,1000000009);
    }
    pair<int,int> gethash(int l,int r){
        return {a.gethash(l,r),b.gethash(l,r)};
    }
    pair<int,int> getrevhash(int l,int r){
        return {a.getrevhash(l,r),b.getrevhash(l,r)};
    }
    bool is_palin(int l,int r){
        return gethash(l,r) == getrevhash(l,r);
    }
    int lex_order(int i,int j,int len){ // O(log(len))
        int ans = 0;
        int lo = 1;
        int hi = len;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(gethash(i,i+mid-1)==gethash(j,j+mid-1)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        if(ans == len){
            return 0;
        }else{
            if(temp[i+ans]<temp[j+ans]){
                return -1; 
            }else{
                return 1;
            }
        }
    }
};
 
 
int n;
double_hash ha;
bool cmp(int i,int j){
    int len = n-max(i,j);
    int oval = ha.lex_order(i,j,len);
    if(oval==0){ //same len string
        if(i>j){
            return true;
        }else{
            return false;
        }
    }else{
        if(oval<0){ //string start with i is less lex_order;
            return true;
        }else{
            return false;
        }
    }
}
 //build suffix array using hashing
vector<int> get_suffix_array(string s){
    n = s.length();
    ha.init(s);
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        arr[i]=i;
    }
    sort(arr.begin(),arr.end(),cmp); //sort using lex_order 
    return arr;
}
 //No of palindromes in string
int palin_count(string s){
    n=s.length();
    ha.init(s);
    int final_ans = 0;
    
    // odd length
    for(int i=0;i<n;i++){
        int lo = 1;
        int hi = min(i-0+1,n-i);
        int ans = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(ha.gethash(i-mid+1,i) == ha.getrevhash(i,i+mid-1)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        final_ans += ans;
    }
    
    // even length
    for(int i=0;i<n;i++){
        int lo = 1;
        int hi = min(i+1,n-i-1);
        int ans = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(ha.gethash(i-mid+1,i) == ha.getrevhash(i+1,i+1+mid-1)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        final_ans += ans;
    }
    
    return final_ans;
}
 
 
void solve(){
    string s;
    cin>>s;
    for(auto v:get_suffix_array(s)){
        cout<<v<<" ";
    }
    cout<<endl;
    cout<<palin_count(s)<<endl;
    
}
 
int main()
{
    solve();
    return 0;
}
