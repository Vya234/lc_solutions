class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open_needed = 0; 
        for (char c : s) {
            if (c == '(') {
                if (open_needed % 2 != 0) {
                    insertions++;  
                    open_needed--;
                }
                open_needed += 2; 
            } else { 
                open_needed--;
                if (open_needed < 0) {
                    insertions++;   
                    open_needed += 2; 
                }
            }
        }
        return insertions + open_needed;
    }
};