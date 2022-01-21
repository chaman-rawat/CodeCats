// https://leetcode.com/problems/lucky-numbers-in-a-matrix/
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> luckyNumber;
        int m = matrix.size();
        int n = matrix[0].size();
        int i, j, min_col;

        // traverse each row
        for (i = 0; i < m; i++)
        {
            min_col = 0;

            // find smallest element in ear row
            for (j = 0; j < n; j++)
                if (matrix[i][j] < matrix[i][min_col])
                    min_col = j;

            // check if the smallest element is greatest in it's column
            for (j = 0; j < m; j++)
            {
                if (matrix[j][min_col] > matrix[i][min_col])
                    break;
            }

            // Lucky number found
            if (j == m)
            {
                luckyNumber.push_back(matrix[i][min_col]);
                return luckyNumber;
            }
        }

        return {};
    }
};