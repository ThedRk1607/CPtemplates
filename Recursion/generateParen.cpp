
void generateParen(string ans,int open,int close){
   if(open==n and close==n){
   	    cout<<ans<<nl;
   	return;
   }

   if(open<n)generateParen(ans+"(",open+1,close);
   if(close<open)generateParen(ans+")",open,close+1);

}
