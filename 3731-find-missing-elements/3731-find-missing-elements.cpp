class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        unordered_set<int> present(nums.begin(), nums.end());
        vector<int> missing;
        for (int val = mn + 1; val < mx; ++val) {
            if (present.find(val) == present.end()) {
                missing.push_back(val);
            }
        }
        return missing;
    }
};