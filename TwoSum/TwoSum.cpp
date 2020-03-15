#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class TwoSum {
public:
    // Implement your solution by completing the below function	
     vector<int> twoSum(vector<int>& nums, int target) {
        int x=nums.size();        
        std::map<int, int> number;
        vector<int> result;
        bool ret = false;
        
        for(int i = 0; i<x; i++){ 
            int tag = target-nums[i];
            if(number.count(tag) && number[tag] !=i){
                result.push_back(i);
                result.push_back(number[tag]);
                ret = true;
                break;  
            }
        if(ret == true){
           break;
        }
        number[nums[i]] = i;
        }
        return result;
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
