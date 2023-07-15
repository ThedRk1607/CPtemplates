
int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
    vector<int> d(n, 1),cnt(n+1,1);
    int ans=0;
    int mx=1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && d[j]+1>d[i]){
                d[i] = d[j] + 1;
               cnt[i]=cnt[j];
        }else if(d[j]+1==d[i])cnt[i]+=cnt[j];
    }
    mx=max(mx,d[i]);
    }

   for(int i=0;i<n;i++)if(d[i]==mx)ans+=cnt[i];
    return ans;
    }
