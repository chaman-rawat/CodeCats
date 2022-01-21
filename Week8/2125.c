// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        vector<int> sdInRows; // store each row security devices if > 0
        int totalBeams = 0;
        for (int i = 0; i < bank.size(); i++)
        {
            int countSd = 0;
            for (int j = 0; j < bank[0].size(); j++)
                if (bank[i][j] == '1')
                    countSd++;
            if (countSd > 0) // add row if have some security device
                sdInRows.push_back(countSd);
        }

        if (sdInRows.size() < 2) // Only 0 or 1 row return 0 beams
            return totalBeams;

        // Multiply each adjacent row and add it to total
        for (int i = 0; i < (sdInRows.size() - 1); i++)
            totalBeams += sdInRows[i] * sdInRows[i + 1];
        return totalBeams;
    }
};