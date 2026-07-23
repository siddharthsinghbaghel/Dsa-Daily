class solution{
    public:

    void movezeros(vectoor<int> &nums){
        int nonzeroindex = 0;
        for (int num : nums){
            if (num != 0){
                nums[nonzeroindex++] = num;
            }
        }
        while (nonzeroindex < nums.size()){
            nums[nonzeroindex++] = 0;
        }
    }
}