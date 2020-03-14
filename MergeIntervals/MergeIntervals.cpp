#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MergeIntervals {
vector> merge(vector>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0;
        vector> output;
        if(intervals.size()==0){
            return output;
        }
        while(i newInterval;
            newInterval.push_back(intervals[i][0]);
            int end=intervals[i][1];
            while(i=intervals[i+1][0]){
                    end=max(end,intervals[i+1][1]);
                    i++;
                }
                else{
                    break;
                }
            }
            newInterval.push_back(end);
            output.push_back(newInterval);
            i++;
            
        }
        if(i==intervals.size()-1){
            output.push_back(intervals[i]);
        }
        return output;
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
