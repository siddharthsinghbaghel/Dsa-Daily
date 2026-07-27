// remove duplicates from sorted array 

class solution{
    public:

    int removeDuplicates(vector<int> & nums){
        int n = nums.size();
        if(n==0) return 0;

        int j = 0;
        for(int i =1; i<n; i++){
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;

    }
}

// second way to remove duplicates from sorted array

class solution{
    public:

    int removeduplicates(vector<int> &nums ){
        int k = 0;

        for(int j =1; j<nums.size(); j++){
            if(nums[k] != nums[j]){
                k++;
                swap(nums[k], nums[j]); // nums[k] = nums[j];
            }
        }
        return k+1; // nums.resize(k+1); 
                    // return nums;
    }
}
