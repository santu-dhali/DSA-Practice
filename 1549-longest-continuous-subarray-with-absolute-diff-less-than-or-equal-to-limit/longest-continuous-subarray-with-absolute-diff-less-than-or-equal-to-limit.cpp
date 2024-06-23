class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxDeque, minDeque;
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            while (!maxDeque.empty() && nums[j] > nums[maxDeque.back()]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(j);

            while (!minDeque.empty() && nums[j] < nums[minDeque.back()]) {
                minDeque.pop_back();
            }
            minDeque.push_back(j);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                i++;
                if (maxDeque.front() < i) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() < i) {
                    minDeque.pop_front();
                }
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
