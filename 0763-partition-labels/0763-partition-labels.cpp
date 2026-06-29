class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int n=s.length();
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        vector<int> part;
        int end=0;
        int len=0;
        for (int i = 0; i < n; i++){
            end=max(end,last[s[i]-'a']);
            len++;
            if(i==end){
                part.push_back(len);
                len=0;
            }
        }
        return part;
    }
};