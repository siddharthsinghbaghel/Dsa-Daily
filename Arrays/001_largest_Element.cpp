class solution{
    public:

    int largest element(vector<int> & nums){
        int largest = nums[0];
        for(int i =1; i<nums.size(); i++){
            if(nums[i]> largest){
                largest = nums[i];
            }
        }
        return largest;
    }
}