class Solution {
public:

    int part(int l,int r,vector<int> &v){
	int pivot=v[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(v[j]<=pivot){
			i++;
			swap(v[i],v[j]);
		}
	}
	swap(v[i+1],v[r]);
	return i+1;
}

void qs(int l,int r,vector<int> &v){
	if(l>=r)return;
	int p=part(l,r,v);
	qs(l,p-1,v);
	qs(p+1,r,v);

}
    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();
        qs(0,n-1,nums);
        return nums;
    }
};
