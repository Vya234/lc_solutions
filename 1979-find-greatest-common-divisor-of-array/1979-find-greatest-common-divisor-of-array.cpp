class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int gcd=1;
        for(int i=2;i<=nums[0];i++){
            if(nums[0]%i==0 && nums[n-1]%i==0) gcd=i;
        }
        return gcd;
    }
};