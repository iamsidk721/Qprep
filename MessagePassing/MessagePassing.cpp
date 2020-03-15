#include <bits/stdc++.h>
using namespace std;

// Implement your solution by completing the below function
bool canMessageBePassed(int n, vector<vector<int>> matrix)
{
        bool poss = true;
        int dir = 0, top = 0;
        int cp = matrix[0][0];
        int c=0;
        int down = n - 1;
        int right = n - 1;
        int left = 0;
        while (top <= down && right >= left)
        {
                if (dir == 0)
                {
                        for (int i = left; i <= right; i++)
                        {
                                c++;
                                if (cp == 0 && c!=n*n)
                                {
                                        return false;
                                }
                                cp = max(cp, matrix[top][i]);
                                cp--;
                        }
                        top++;
                }
                if (dir == 1)
                {
                        for (int i = top; i <= down; i++)
                        {
                                c++;
                                if (cp == 0 && c!=n*n)
                                {
                                        return false;
                                }
                                cp = max(cp, matrix[i][right]);
                                cp--;
                        }
                        right--;
                }
                if (dir == 2)
                {
                        for (int i = right; i >= left; i--)
                        {
                                c++;
                                if (cp == 0 && c!=n*n)
                                {
                                        return false;
                                }
                                cp = max(cp, matrix[down][i]);
                                cp--;
                        }
                        down--;
                }
                if (dir == 3)
                {
                        for (int i = down; i >= top; i--)
                        {
                                c++;
                                if (cp == 0 && c!=n*n)
                                {
                                        return false;
                                }
                                cp = max(cp, matrix[i][left]);
                                cp--;
                        }
                        left++;
                }
                dir = (dir + 1) % 4;
        }
        return poss;
}

int main()
{
        int n, s, m;
        cin >> n >> s >> m;
        assert(1 <= n && n <= 500);
        assert(1 <= s && s <= 1e5);
        assert(1 <= m && m <= 1e5);

        vector<vector<int>> maze(n, vector<int>(n, 0));
        maze[0][0] = s;

        for (int i = 0; i < m; ++i)
        {
                int x, y, p;
                cin >> x >> y >> p;
                assert(0 <= x && x < n);
                assert(0 <= y && y < n);
                assert(1 <= p && p <= 1e5);
                maze[x][y] = max(maze[x][y], p);
        }
        bool possible = canMessageBePassed(n, maze);
        cout << (possible ? "Yes\n" : "No\n");
}