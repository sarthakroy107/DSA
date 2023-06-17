class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int x = nums.size();        
        for(int i = 0; i < nums.size()-2; i++) {
            if(i == 0 || (i>0 && nums[i] != nums[i-1])) {
                int low = i+1, high = x-1, sum =  0 - nums[i];
                while(low < high) {
                    if(!(nums[i] + nums[low] + nums[high])) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[low]);
                        v.push_back(nums[high]);
                        ans.push_back(v);

                        while(low<high && nums[low] == nums[low+1]) low++;
                        while(low<high && nums[high] == nums[high-1]) high--;

                        low++, high--;
                    }
                    else if(nums[i] + nums[low] + nums[high] < 0) low++;
                    else high--;
                }
            }
        }
        return ans;
    }
};