// https://leetcode.com/problems/reshape-the-matrix/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c)
            return mat;

        vector<vector<int>> newMat(r, vector<int> (c));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                newMat[(n * i + j) / c][(n * i + j) % c] = mat[i][j];

        return newMat;
    }
};