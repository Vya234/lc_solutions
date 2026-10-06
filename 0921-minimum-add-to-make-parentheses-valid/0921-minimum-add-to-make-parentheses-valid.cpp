class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;
        int additions = 0;
        for (char c : s) {
            if (c == '(') open_needed++;
            else {
                if (open_needed > 0) open_needed--; 
                else additions++;   
            }
        }
        return open_needed + additions;
    }
};