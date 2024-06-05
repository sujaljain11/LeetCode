class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int days = 0, total = 0, cnt = 0;
        queue <pair<int, int> > q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i <= n - 1; i++) {
            for(int j = 0; j <= m - 1; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] != 0) total++;
            }
        }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty()) {
            int k = q.size();
            cnt += k;
            while(k--) {
                pair<int, int> x = q.front();
                q.pop();
                for(int i = 0; i <= 3; i++) {
                    int nx = x.first + dx[i];
                    int ny = x.second + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if(!q.empty()) days++;
        }
        return total == cnt ? days: -1;
    }
};