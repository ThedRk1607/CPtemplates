
int longestBitonicSeq(vector<int>&arr,int n){
   vector<int>dp1(n,1),dp2(n,1);
  for(int i=0;i<n;i++){
     for(int j=0;j<i;j++){
       if(arr[i]>arr[j]){
         dp1[i]=max(dp1[i],dp1[j]+1);
       }
     }
  }

  for(int i=n-1;i>=0;i--){
    for(int j=n-1;j>i;j--){
       if(arr[i]>arr[j]){
           dp2[i]=max(dp2[i],dp2[j]+1);
       }
    }
  }

  int mx=-1;
  FOR(i,0,n)amax(mx,dp1[i]+dp2[i]-1);
  
}
