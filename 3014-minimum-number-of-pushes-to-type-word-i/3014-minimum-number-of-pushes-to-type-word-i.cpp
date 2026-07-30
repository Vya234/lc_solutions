class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int totalPushes = 0;
        int presses = 1;
        while (n > 0) {
            int currentBatch = min(n, 8);
            totalPushes += currentBatch * presses;
            n -= currentBatch;
            presses++;
        }
        return totalPushes;
    }
};