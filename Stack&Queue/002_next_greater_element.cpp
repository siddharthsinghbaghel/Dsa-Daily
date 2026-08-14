class solution{
    public:

    vector<int>nextgreater(vector<int>&nums1 , vector<int>&nums2){
        unordered_map<int, int> mp;
        stack<int> st;
// iterate through nums2 in reverse order
        for(int i = nums2.size() - 1; i >= 0; i--){
            // pop elements from the stack until we find a greater element or the stack is empty
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            // if the stack is empty, there is no greater element, so we store -1 in the map 
            // and if the stack is not empty, we store the top element of the stack as the next greater element in the map
            if(st.empty()){
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        // create a result vector to store the next greater elements for nums1

        vector<int> result(nums1.size());
        // iterate through nums1 and check if the element exists in the map,
        //  if it does, we store the next greater element in the result vector, otherwise we store -1
        for(int i = 0; i < nums1.size(); i++){
            if(mp.find(nums1[i]) != mp.end()){
                result[i] = mp[nums1[i]];
            } else {
                result[i] = -1;
            }
        }
        return result;
    }           
};
//input: nums1 = [4,1,2], nums2 = [1,3,4,2]
//output: [-1,3,-1]

//explana