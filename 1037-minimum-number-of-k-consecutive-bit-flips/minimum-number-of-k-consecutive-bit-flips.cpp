class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> flipQueue;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (!flipQueue.empty() && flipQueue.front() == i) {
                flipQueue.pop();
            }

            if (nums[i] == (flipQueue.size() % 2 == 0 ? 0 : 1)) {
                if (i + k > n) {
                    return -1;
                }
                flipQueue.push(i + k);
                ++count;
            }
        }

        return count;
    }
};