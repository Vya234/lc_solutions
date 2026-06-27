class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++) freq[nums[i]]++;
        int max_size=1;
        if(freq.count(1) && freq[1]>=3){
            if(freq[1]%2==0) max_size=freq[1]-1;
            else  max_size=freq[1];
        }
        for(auto it : freq){
            long long x=it.first;
            if(x==1) continue;
            int len=0;
            while(true){
                auto it=freq.find(x);
                if(it==freq.end()){
                    len--;
                    break;
                }
                else if(it->second>=2){
                    if (x > 1000000000LL){
                        len+=1;
                        break;
                    }
                    len+=2;
                    x=x*x;
                }
                else{
                    len+=1;
                    break;
                }
            }
            max_size = max(max_size, len); 
        }
        return max_size;
    }
};