class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        unordered_map<int, int> remainder_count;
        remainder_count[0] = 1;
        
        int sum = 0;
        int count = 0;

        for (int num : nums) {
            sum += num;
            int remainder = sum % k;
            if (remainder < 0) remainder += k;
            
            if (remainder_count.find(remainder) != remainder_count.end()) {
                count += remainder_count[remainder];
            }

            remainder_count[remainder]++;
        }

        return count;
    }
};
