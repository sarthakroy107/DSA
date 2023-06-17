class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's Voting Algorithm
        int majorityElement;
        int count = 0;

        for(auto it: nums) {
            if(majorityElement != it && !count) {
                majorityElement = it;
                count++;
            }else if(majorityElement == it) {
                count++;
            }
            else{
                count--;
            }
        }
        return majorityElement;
    }
};