#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class SpiralMatrix {
 private:
        int m; // rows
        int n; // cols
        vector<int> result;
    
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix)
        {
            m = matrix.size();
            if (m < 1)
                return result;
            n = matrix[0].size();
            
            int rowLoop = 0;
            int colLoop = 1;
            
            int row = -1; // Ensure that it initially starts at 0
            int col = -1; // Ensure that it initially starts at 0
            
            // Amount of horizontal/vertical traversals
            while(result.size() < m*n)
            {
                // Left to Right
                int limit = rowLoop++/2;
                for (row++, col++; col < n - limit; col++)
                    result.push_back(matrix[row][col]);
                
                // Top to Bottom
                limit = colLoop++/2;
                for (row++, col--; row < m - limit; row++)
                    result.push_back(matrix[row][col]);
                
                // Half way exit
                if (result.size() >= m*n)
                    break;
                
                // Right to Left
                limit = rowLoop++/2;
                for (row--, col--; col >= 0 + limit; col--)
                    result.push_back(matrix[row][col]);
                
                // Bottom to Top
                limit = colLoop++/2;
                for (row--, col++; row >= 0 + limit; row--)
                    result.push_back(matrix[row][col]);
            }
            
            return result;
        }
};

int main() {
    FastIO();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix;
	ReadMatrix<int>().TwoDMatrix(n, m, matrix);
	vector<int> result = SpiralMatrix().spiralOrder(matrix);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
