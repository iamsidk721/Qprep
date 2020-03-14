#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MergeIntervals {
	public:
 vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        vector<vector<int>> res;
        int x=inter.size();
		for(int i=1;i<=x;i++){
			
            vector<int> ins;
            if(i<x && inter[i-1][1] >= inter[i][0]){
                inter[i][0] = min(inter[i-1][0],inter[i][0]);
                inter[i][1] = max(inter[i-1][1], inter[i][1]);
            }
            else{
                ins.push_back(inter[i-1][0]);
                ins.push_back(inter[i-1][1]);
                res.push_back(ins);
            }
        }
        return res;
    }
};

int main() {
    FastIO();
	int n;
	cin >> n;
	vector<vector<int>> nums;
	ReadMatrix<int>().TwoDMatrix(n, 2, nums);
	vector<vector<int>> result = MergeIntervals().merge(nums);
	PrintMatrix<int>().TwoDMatrix(result);
	return 0;
}
