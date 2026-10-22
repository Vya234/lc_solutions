class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool inc=true;
        bool dec=true;
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            if(!(nums[(i+1)%n] == (nums[i]+1) % n))
                inc=false;
        }
        for(int i=0;i<n;i++){
            if(!(nums[(i+1)%n] == (nums[i]-1+n) % n))
                dec=false;
        }
        if(inc==false && dec==false) return -1;
        int index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                index=i;
                break;
            }
        }
        if (inc==true) {
            res = min(res, index);         
            res = min(res, n - index + 2); 
        }
        if (dec==true) {
            res = min(res, index + 2);       
            res = min(res, 1 + (n-1-index));
        }
        return res;
    }
};