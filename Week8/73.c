// https://leetcode.com/problems/set-matrix-zeroes/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int setFirstRow = false;
        int setFirstCol = false;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) // 0 element found
                {
                    if (i == 0)
                        setFirstRow = true;
                    if (j == 0)
                        setFirstCol = true;
                    // Set 1st element of ith row to 0
                    matrix[i][0] = 0;
                    // Set 1st element of jth column to 0
                    matrix[0][j] = 0;
                }

        // Set all rows and columns except first
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // Set first row to 0
        if (setFirstRow)
            for (int j = 1; j < n; j++)
                matrix[0][j] = 0;

        // Set first column to 0
        if (setFirstCol)
            for (int i = 1; i < m; i++)
                matrix[i][0] = 0;
    }
};