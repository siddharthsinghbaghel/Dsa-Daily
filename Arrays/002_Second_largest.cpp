class solution{
    public:

    int secondlargest(vector<int> & nums){
        int prev = -1;
        int curr = nums[0];

        for(int i =1; i<nums.size(); i++){
            if(nums[i]>curr){
                
                prev = curr;
                curr = nums[i];
            }
            else if(nums[i]<curr && nums[i] > prev){
                prev =  nums[i];
            }
        }
        return prev;
    }
}