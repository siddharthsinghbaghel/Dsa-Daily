class solution{
    public:
    int subarraysum(vector<int> & nums , int k ){
        unordered_map<int,int> mp;
        int sum = 0;
        int count = 0;

        for(int i =0; i<nums.size(); i++){
            sum += nums[i];

            if(sum == k){
                count++;
            }

            if(mp.find(sum - k) != mp.end()){
                count += mp[sum - k];
            }

            mp[sum]++;
        }
        return count;
    }
}


// First Understand Prefix Sum

// Suppose

// nums = [2,3,1,4]
// Prefix Sum Array

// | Index | Element | Prefix Sum |
// | ----- | ------- | ---------- |
// | 0     | 2       | 2          |
// | 1     | 3       | 5          |
// | 2     | 1       | 6          |
// | 3     | 4       | 10         |

// So
// PrefixSum[i]
// =
// Sum of all elements from 0 to i






// Main Idea

// Suppose
// Current Prefix Sum = sum
// You want a subarray whose sum is k.

// Suppose earlier there was another prefix sum

// oldSum

// Then

// sum - oldSum = k

// Rearrange

// oldSum = sum - k

// That's exactly why we search

// mp.find(sum-k)







// Example

// Suppose

// nums = [1,2,3]

// k = 3




// Iteration 1

// Element = 1

// sum = 1

// Check

// sum == k ?

// 1==3

// No

// Check

// sum-k

// 1-3=-2

// Not found

// Store

// mp

// 1 : 1






// Iteration 2

// Element =2

// sum=3

// Check

// sum==k

// 3==3

// YES

// So

// count=1

// Subarray

// [1,2]

// Now

// sum-k

// 3-3=0

// 0 doesn't exist.

// Store

// mp

// 1 :1

// 3 :1






// Iteration 3

// Element =3

// sum=6

// Now

// sum==k

// 6==3

// No

// Check

// sum-k

// 6-3=3

// Does hashmap contain

// 3 ?

// YES

// That means

// There exists a prefix sum

// 3

// Remove it

// 6-3=3

// Subarray

// [3]

// So

// count++







// Final

// count=2

// Subarrays

// [1,2]

// [3]