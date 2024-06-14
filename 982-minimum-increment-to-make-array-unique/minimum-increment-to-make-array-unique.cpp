class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        } 

        sort(nums.begin(), nums.end());
        int moves = 0;
        int needed = nums[0];

        for (int num : nums) {
            if (num < needed) {
                moves += needed - num;
            }
            needed = max(needed, num) + 1;
        }

        return moves;
    }
};
