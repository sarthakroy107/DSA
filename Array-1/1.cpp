/*My initial approach: used recursion and used the method "pick or skip".
Errors: 
Test Case-1:
    [0,4,3,0]
    0
Answer is [0,3] but was giving [] because sum was initialised with 0 and because of t == sum
Test Case-2:
    [-1,-2,-3,-4,-5]
    -8
 */
class Solution {
public:
    bool answer(vector<int>& nums, int t, int sum, vector<int>& ans, int i) {
        if(sum == INT_MIN) sum = 0;
        if( i < nums.size()) {
            sum += nums[i];
            cout<<"sum += "<<sum<<endl;
            ans.push_back(i);
            if(answer(nums, t, sum, ans, i+1)) return true;
            sum -= nums[i];
            cout<<"sum -= "<<sum<<endl;
            ans.pop_back();
            if(answer(nums, t, sum, ans, i+1)) return true;
        }
        if(t == sum) return true;
        return false;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        answer(nums, target, INT_MIN, ans, 0);
        return ans;
    }
};

//That's what happen when you don't read the question properly

//Optimal way is to use Hashmap
// Revise Hashmap

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) {
            sum = nums[i];
            int diff = target - sum;
            if(m.find(diff) != m.end()) {
                return {i, m[diff]};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};