#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MergeIntervals {
	public:
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        int x=intervals.size();
		for(int i=1;i<=x;i++){
			
            vector<int> insidearray;
            if(i<x && intervals[i-1][1] >= intervals[i][0]){
                intervals[i][0] = min(intervals[i-1][0],intervals[i][0]);
                intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
            }
            else{
                insidearray.push_back(intervals[i-1][0]);
                insidearray.push_back(intervals[i-1][1]);
                result.push_back(insidearray);
            }
        }
        return result;
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
