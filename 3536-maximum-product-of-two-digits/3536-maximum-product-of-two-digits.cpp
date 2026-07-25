class Solution {
public:
    int maxProduct(int n) {
        vector<int> dig;
        while(n>0){
            int rem=n%10;
            dig.push_back(rem);
            n=n/10;
        }
        sort(dig.begin(),dig.end());
        int s=dig.size();
        return dig[s-1]*dig[s-2];
    }
};