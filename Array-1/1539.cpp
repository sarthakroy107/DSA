class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        long long low = 0, high = arr.size()-1;
        //if(arr.size() == arr[high]) return arr[high] + k;
        long long x, mid;
        while( low <= high) {
            mid = low + (high-low)/2;
            x = arr[mid] - mid -1;
            cout<<"MID: "<<mid<<" X: "<<x<<endl;
            if( x >= k) high = mid-1;
            else low = mid+1;
        }
         if( k > x ) return arr[mid] - x + k;
         else return arr[mid] - x + k -1;
    }
};