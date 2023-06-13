//Dutch National flag algorithm
/*
We can solve this using any in-pace sorting algorithm like merge sort, bubble sort etc.
Optimal approach is to use Dutch National Flag Algorithm.

Take 3 pointers- low, mid & high.
set low to index 0
set high to nums.size()-1
mid will begin from 0
Idea is to keep all the 0s before low and all the 2s after high.
Mid pointer traverses through array.
If mid == 0, then swap with low and increment both low & mid by 1.
If mid == 1,then increment mid by 1.
If mid == 2, then decrement high by 1.
*/
//Learn from your leetcode solution

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if(nums[mid] == 2) {
                swap(nums[high], nums[mid]);
                high--;
            }else if(nums[mid] == 1) mid++;
        }
    }
};