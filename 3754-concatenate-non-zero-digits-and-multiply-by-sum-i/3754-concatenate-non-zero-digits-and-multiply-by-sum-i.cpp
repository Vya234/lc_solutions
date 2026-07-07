class Solution {
public:
    long long sumAndMultiply(int n) {
        long long copy=0;
        int sum=0;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            if(rem!=0) copy=copy*10+rem;
            n/=10;
        }
        long long x=0;
        while(copy>0){
            int rem=copy%10;
            x=x*10+rem;
            copy/=10;
        }

        if(x!=0) return (x*sum);
        return 0;
    }
};