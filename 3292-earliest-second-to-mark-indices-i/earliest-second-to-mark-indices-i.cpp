class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& changeIndices, int sec, int n, int m){
        vector<int>lastInd(n+1, -1); // keeping track of last Index in changeIndices for each element of nums.

        for(int i=0; i<=sec; i++){
            int ind = changeIndices[i];
            lastInd[ind] = i+1;
        }

        for(int i=1; i<=n; i++){
            if(lastInd[i] == -1){
                return false;    // checking if any index is left with -1 or not. If it's found then marking all indices is not possible
            }
        }

        int marking_sec = 0;
        map<int, int>mp; // keeping track of index and element of the vector lastInd in sorted order;
        for(int i=1; i<=n; i++){
            int position = lastInd[i];
            mp[position] = nums[i-1];
        }

        for(auto it: mp){
            if(it.second + 1 + marking_sec <= it.first){ //checking if marking time is less than or equal the last index it appears.
                marking_sec += it.second+1;
            }else{
                return false;
            }
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();

        for(int i=0; i<m; i++){
            if(solve(nums, changeIndices, i, n, m)){
                return i+1;
            }
        }
        return -1;
    }
};