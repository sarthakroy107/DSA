class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++) {
            vector<int> v;
            int x = 1;
            v.push_back(x);
            for(int j = 1; j<i;j++) {
                x = x*(i-j);
                x = x/j;
                v.push_back(x);
            }
            ans.push_back(v);
        }
        return ans;
    }
};