class Solution {
public:
    bool checkString(string s) {
        int i=0;
        int n=s.size();
        if(n==1) return true;
        while(i<n && s[i]=='a') i++;
        for(int j=i;j<n;j++) if(s[j]=='a') return false;
        return true;
    }
};