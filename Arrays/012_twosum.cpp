class solution
public:
vector<int>twosum(vector<int>&nums, int target){
    unordered_map<int,int>mp;

    for(int i =0; i<nums.size(); i++){

        int remains = target -nums[i];
        if(mp.find(remains) != mp.end()){
            return {mp[remains], i};      // {remains,nums[i]}
        }
        mp[nums[i]] = i;
    }
    return{-1,-1};
}