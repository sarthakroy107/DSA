class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum == k) {
                count++;
            }
            int x = sum - k;
            if(m.find(x) != m.end()) count += m[x];
            m[sum]++;
        }
        return count;
    }
};
