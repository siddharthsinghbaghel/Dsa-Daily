class soluttion{
    public:

    int missingNumbers(vector<int> & nums){
        int actualsum = 0;
        int expectedsum = n * (n+1)/2;

        for(int num: nums){
            actualsum += num;
        }
        return expectedsum - actualsum;
    }
};