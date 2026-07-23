class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        int powerOfTwo = 1;
        while (powerOfTwo <= n) powerOfTwo *= 2;
        return powerOfTwo;
    }
};