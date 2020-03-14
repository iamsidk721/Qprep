#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MatrixTraversal {
public:
    // Implement your solution by completing the below function	
    vector<int> traversalPath(vector<vector<int>>& matrix, int currPosX, int currPosY, int dirToMove, int stepsToMove, int m , int n) {
        vector<int> res;
		for(int i=0;i<stepsToMove;i++){
    if(dirToMove==1)
            { if(currPosX==m-1 && currPosY==n-1)
            {
                res.push_back(-1);
                
            }
             else if(currPosY==n-1)
             {currPosX=currPosX+1;
             res.push_back(matrix[currPosX][0]);
             }
             else
             {currPosY=currPosY+1;
             res.push_back(matrix[currPosX][currPosY]);
             }
                
            }
    if(dirToMove==2)
            {if(currPosX==m-1)
            {
                res.push_back(-1);
                
            }else{
             currPosX=currPosX+1;
            res.push_back(matrix[currPosX][currPosY]);
            
            }}
    if(dirToMove==3)
            { if(currPosX==0 && currPosY==0)
            {
                res.push_back(-1);
                
            }
              else if(currPosY==0)
             {currPosX=currPosX-1;
             res.push_back(matrix[currPosX][n-1]);
             
             }
             else
             {currPosY=currPosY-1;
             res.push_back(matrix[currPosX][currPosY]);
            }
                
            }
    if(dirToMove==4)
            {if(currPosX==0)
            {
               res.push_back(-1);
            }else{
             currPosX=currPosX-1;
            res.push_back(matrix[currPosX][currPosY]);
            
            } }      
    
            
            
    }   int x=res.size(); 
        int z=-1;
        vector <int> y;
        y.push_back(z);
        for(int i=0;i<x;i++)
        {if(res[i]==-1){
        return y;
        break;}
        else{
	    return res;}}
    }
};

int main() {
    FastIO();
	int m, n;
	cin >> n >> m;
	vector<vector<int>> matrix;
	ReadMatrix<int>().TwoDMatrix(n, m, matrix);

	int currPosX, currPosY, dirToMove, stepsToMove;
	cin >> currPosX >> currPosY;
	cin >> dirToMove >> stepsToMove;

	vector<int> result = MatrixTraversal().traversalPath(matrix, currPosX, currPosY, dirToMove, stepsToMove,n,m);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
