class solution{
    public:
    int longestsum(vector<int>&nums, long long k){

        int i =0;
        int ans = 0;
        int sum = 0;
        int n = nums.size();

        for(int j =0 ; j<n; j++){
            sum += nums[j];

            while(sum>k && i<=j){
                sum -= nums[i];
                i++;
            }
            if(sum == k){
                ans = max(ans, j-i+1);
            }
        }
        return ans;
    };
}