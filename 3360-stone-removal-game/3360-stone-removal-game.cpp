class Solution {
public:
    bool canAliceWin(int n) {
        int v = 10;
        bool alice = true;
        while (n >= v) {
            n -= v;
            if (alice) alice = false;
            else alice = true;
            v--;
        }
        return !alice;
    }
};