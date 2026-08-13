class solution{
    public:
    string largestnumber(vector<int> &nums){
        vector<string> strnums;
        //convert all the integer to strings 
        for(int num: nums){
            strnums.push_back(to_string(num));
        }
        //custom comparator for sorting
        sort(strnums.begin(), strnums.end(), [](string &a, string &b){
            return a + b > b + a;
        });
        //if after sorting first string is 0 then return "0"
        if(strnums[0] == "0") return "0";
        // concatenate all strings to form the result
        string result = "";
        for(string &s:strnums){
            result += s;
        }
        return result;

    }
};