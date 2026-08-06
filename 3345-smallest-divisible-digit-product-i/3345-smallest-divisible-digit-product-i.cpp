class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(true){
            int copy=num;
            int mul=1;
            while(copy>0){
                mul*=(copy%10);
                copy/=10;
            }
            if(mul%t==0) break;
            num++;
        }
        return num;
    }
};