class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row_masks;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) row_masks[row] |= (1 << (col - 2));
        }
        int left_mask   = 0b00001111; 
        int right_mask  = 0b11110000; 
        int middle_mask = 0b00111100; 
        int max_families = (n - row_masks.size()) * 2;
        for (const auto& [row, mask] : row_masks) {
            bool left_free   = (mask & left_mask) == 0;
            bool right_free  = (mask & right_mask) == 0;
            bool middle_free = (mask & middle_mask) == 0;
            if (left_free && right_free) max_families += 2;
            else if (left_free || right_free || middle_free) max_families += 1;
        }
        return max_families;
    }
};