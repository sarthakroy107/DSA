class Solution {
public:
    long long time(vector<int> piles, long long t) {
        long long ans = 0;
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i]%t != 0) ans += piles[i]/t + 1;
            else ans += piles[i]/t;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *(max_element(piles.begin(), piles.end()));
        int ans = -1;

        while(low <= high) {
            long long mid = low + (high-low)/2;
            long long t = time(piles, mid);
            if(t > h) low = mid + 1;
            else {
                ans = mid;
                high = mid - 1; }
        }
        return ans;
    }
};