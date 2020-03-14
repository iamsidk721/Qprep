#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MergeIntervals {
public:
	 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a, vector<int>&b){
            if(a[0]<b[0])
                return true;
            if(a[0] == b[0]){
                if(a[1] < b[1])
                    return true;
            }
            return false;
            });
        vector<vector<int>> res = intervals;
        if(!intervals.size())
            return res;
        for(int i = 1; i<res.size(); i++){
            if(res[i-1][0] <= res[i][0] && res[i-1][1] >= res[i][0] && res[i-1][1] <=res[i][1]){
                res[i-1][1] = res[i][1];
                res.erase(res.begin() + i);
                i--;
            }else if(res[i-1][0] < res[i][0] && res[i-1][1] > res[i][1]){
                res.erase(res.begin() + i);
                i--;
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
