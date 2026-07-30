class solution{
    public:

    int findfirstocc(vector<int> &arr, int n , int target){
        int s = 0 , e = n-1;
        int ans = -1;
        
        while(s<=e){
            int mid = s + (e - s)/2;

            if(arr[mid] == target){
                ans = mid;
                e = mid -1;
            }
            else if(target <arr[mid]){
                e = mid -1;

            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }

    int findlastocc(vector<int> & arr, int n , int target){
        int s = 0, e = n-1;
        int ans = -1;

        while(s <= e){
            int mid = s + (e - s)/2;
            if(arr[mid] == target){
                ans = mid;
                s = mid + 1;

            }
            else if(target < arr[mid]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> & arr, int target){
        int n = arr.size();
        int first = findfirstocc(arr, n , target);
        int last = findlastocc(arr, n, target);
        return {first, last};
    }
};
