/*
1162. As Far from Land as Possible
Medium
4K
105
Companies
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

 

Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:


Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/


//https://leetcode.com/problems/as-far-from-land-as-possible/description/?source=submission-ac

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int levels[100][100]; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    levels[i][j] = 0;
                } else {
                    levels[i][j] = -1; 
                }
            }
        }
        
        int maxLevel = -1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (const auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && levels[newX][newY] == -1) {
                    levels[newX][newY] = levels[x][y] + 1;
                    q.push({newX, newY});
                    maxLevel = max(maxLevel, levels[newX][newY]);
                }
            }
        }
        
        return maxLevel > 0 ? maxLevel : -1; 
    }
};
