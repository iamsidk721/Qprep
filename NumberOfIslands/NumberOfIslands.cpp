#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class NumberOfIslands {
public:
    // Implement your solution by completing the below function
	bool isvalid(int x,int y,int n,int m)
	{
		return (x>=0 && y>=0 && x<n && y<m);
	}

	void dfs(vector<string>& grid,vector<vector<bool>>& visit,int i,int j,int n,int m)
	{
		visit[i][j]=true;
		int dx[4]={1,-1,0,0};
		int dy[4]={0,0,1,-1};

		for(int k=0;k<4;k++)
		{
			int x=i+dx[k];
			int y=j+dy[k];
			if(isvalid(x,y,n,m) && !visit[x][y] && grid[x][y]=='1')
			{
				dfs(grid,visit,x,y,n,m);
			}
		}

	}

    int numIslands(vector<string>& grid) {
        int x = 0;
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<bool>> visit(n,vector<bool>(m,false));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(!visit[i][j] && grid[i][j]=='1')
				{
					x++;
					dfs(grid,visit,i,j,n,m);
				}
			}
		}
        return x;
    }
};

int main() {
    FastIO();
	int n, m;
	cin >> n >> m;
	vector<string> grid;
	ReadMatrix<string>().OneDMatrix(n, grid);
	if(n==0 || m==0)
	{
		cout<<0<<endl;
		return 0;
	}
	int result = NumberOfIslands().numIslands(grid);
	cout << result;
	return 0;
}