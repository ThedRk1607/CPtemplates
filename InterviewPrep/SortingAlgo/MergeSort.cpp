Class Solution {
public:

    void Merge(int l,int mid,int r,vector<int> &v){
	vector<int> tmp;
	int left=l, right=mid+1;
	while(left<=mid and right<=r){
		if(v[left]<v[right])tmp.push_back(v[left++]);
		else tmp.push_back(v[right++]);
	}
	while(left<=mid)tmp.push_back(v[left++]);
	while(right<=r)tmp.push_back(v[right++]);
	for(int i=l;i<=r;i++)v[i]=tmp[i-l];

	
}

void MergeSort(int l,int r,vector<int> &v){
	if(l>=r)return;
	int mid=(l+r)/2;
	 MergeSort(l,mid,v);
	 MergeSort(mid+1,r,v);
	 Merge(l,mid,r,v);



}
    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();
        MergeSort(0,n-1,nums);
        return nums;
    }
};
