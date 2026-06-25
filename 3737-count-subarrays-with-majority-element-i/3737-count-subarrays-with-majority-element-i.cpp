class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int size=0;
            int cnt=0;
            for(int j=i;j<nums.size();j++){
                size++;
                if(nums[j]==target) cnt++;
                if(cnt>size/2) ans++;
            }
        }
        return ans;
    }
};