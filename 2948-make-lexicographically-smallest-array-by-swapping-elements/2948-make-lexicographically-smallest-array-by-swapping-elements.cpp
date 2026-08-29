class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int>index(n,-1);
        int i=0;int j=0;
        int prev=v[0].first;
        while(j<nums.size()){
            if(abs(prev-v[j].first)<=limit){
                index[j]=v[j].second;
                prev=v[j].first;
                j++;
            }
            else{
                sort(index.begin()+i,index.begin()+j);
                i=j;
                prev=v[j].first;
            }
        }
                sort(index.begin()+i,index.end());
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[index[i]]=v[i].first;
        }
        return ans;
    }
};