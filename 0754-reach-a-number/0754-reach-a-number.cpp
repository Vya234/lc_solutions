class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int moves=1;
        int sum=0;
        while(sum<target || (sum-target)%2!=0){
            sum+=moves;
            moves++;
        }
        return moves-1;
    }
};