class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> hasSingle(2048, false);
        vector<int> singles;
        for (int x : nums) {
            if (!hasSingle[x]) {
                hasSingle[x] = true;
                singles.push_back(x);
            }
        }
        vector<bool> hasPair(2048, false);
        vector<int> pairs;
        for (int i = 0; i < singles.size(); ++i) {
            for (int j = i; j < singles.size(); ++j) {
                int pairXor = singles[i] ^ singles[j];
                if (!hasPair[pairXor]) {
                    hasPair[pairXor] = true;
                    pairs.push_back(pairXor);
                }
            }
        }
        vector<bool> hasTriplet(2048, false);
        int uniqueTripletsCount = 0;
        for (int p : pairs) {
            for (int x : singles) {
                int tripletXor = p ^ x;
                if (!hasTriplet[tripletXor]) {
                    hasTriplet[tripletXor] = true;
                    uniqueTripletsCount++;
                }
            }
        }
        return uniqueTripletsCount;
    }
};