class solution{
    public:

    int maxproductsubarary(vector<int> & nums){
        int n = nums.size();
        int maxprod = nums[0];
        int currmax = nums[0];
        int currmin = nums[0];

        for(int i =0; i<n; i++){
            int temp = currmax;
            currmax =max({nums[i], nums[i]* currmax , nums[i] * currmin});
            currmin = min({nums[i], nums[i] * temp, nums[i] * currmin});
            maxprod = max(maxprod, currmax);
        }
        return maxprod;
    }
}