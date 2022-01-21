// https://leetcode.com/problems/toeplitz-matrix/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int cur_diag_value;

        // Lower Diagonals
        for (int i = m - 1, diff = m; i >= 0 && diff--; i--)
        {
            cur_diag_value = matrix[i][i - diff];
            for (int j = i; j < m && (j - diff) < n; j++)
                if (cur_diag_value != matrix[j][j - diff])
                    return false;
        }

        // Upper diagonals
        for (int i = n - 1, diff = n; i > 0 && diff--; i--)
        {
            cur_diag_value = matrix[i - diff][i];
            for (int j = i; (j - diff) < m && j < n; j++)
                if (cur_diag_value != matrix[j - diff][j])
                    return false;
        }
        return true;
    }
};