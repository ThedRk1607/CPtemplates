 vector<long long> findXSum(vector<int>& nums, int k, int x) {
        map<long long,long long>mp;
        set<pair<long long,long long>>left,right;
        int n=nums.size();
        vector<long long>ans;long long sum=0;
        for(int i=0;i<n;i++)left.insert({mp[nums[i]],nums[i]});
       //can do both insert and remove op
        auto update=[&](int x,int v){
            if(right.count({mp[x],x})){
                right.erase({mp[x],x});
                sum-=1LL*mp[x]*x;
                 mp[x]+=v;
                 sum+=mp[x]*x;
                 right.insert({mp[x],x});
            }else if(left.count({mp[x],x})){
                left.erase({mp[x],x});
                 mp[x]+=v;
                 left.insert({mp[x],x});
            }
        };
     //similar to support queries to find sum of top k elements;
        auto bal=[&](){
            while(right.size()<x and left.size()){
                auto it=*left.rbegin();
                right.insert(it);
                sum+=1LL*it.first*it.second;
                left.erase(it);
            }
            if(left.size()==0)return ;
            while(true){
                auto it1=*left.rbegin();
                auto it2=*right.begin();
                if(it2<it1){
                    left.erase(it1);
                    right.erase(it2);
                    sum-=it2.first*it2.second;
                    sum+=it1.first*it1.second;
                    left.insert(it2);
                    right.insert(it1);
                }else break;
            }
        };

        for(int i=0;i<n;i++){
            update(nums[i],1);
            if(i>=k)update(nums[i-k],-1);
            if(i>=k-1){
                bal();
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
