#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class TwoSum {
public:
    // Implement your solution by completing the below function	
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v; int k,l;
        for(int i=0;i<nums.size();i++)
		{
          for(int j=0;j<nums.size();j++)
		{
          if(i+j==target && i!=j)
		  {
           v.push_back(i);
		   v.push_back(j);
		   break;
		  }
		}
		}
        return v;
    }
};

int main() {
	FastIO();
	int n, target;
	cin >> n;
	vector<int> nums;
	ReadMatrix<int>().OneDMatrix(n, nums);
	cin >> target;
	vector<int> result = TwoSum().twoSum(nums, target);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
