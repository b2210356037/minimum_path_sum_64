#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n+1, 350); //max value do not exceed 350, may be used another value
        dp[n-1] = 0;

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                dp[j] = min(dp[j] + grid[i][j], grid[i][j] + dp[j+1]);
            }
        }
        return dp[0];
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid{
            {1, 2, 3},
            {4, 5, 6}
    };
    int res = s.minPathSum(grid);
    cout << res;
    return 0;
}
