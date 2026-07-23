class solution{
    public:

    void movezeros(vector<int> &nums){
        int nonzeroindex = 0;
        for (int i =0; i<nums.size() ; i++){
            if (nums[i] != 0){
                nums[nonzeroindex++] = nums[i];
            }
        }
        while (nonzeroindex < nums.size()){
            nums[nonzeroindex++] = 0;
        }
    }
}