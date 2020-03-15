#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class Solution {
public:
    vector<int> TwoSum(vector<int>& nums, int target) {
      int i=0,j=nums.size()-1; int x=nums.size();
        vector <int>  a = nums;
        sort(a.begin(),a.end());
        while(i<j)
        {
                   
				   if(a[i]+a[j]==target)
                   break;
                   
				   else if(a[i]+a[j]>target)
                    j--;
                  
				    else
                    i++;
        }   
		int c=0;int l,m;
        
		for(int k=0;k<x;k++)
        {
            if(nums[k]==a[i]&&(c==0))
            {
                l=k;c=1;
                
            }
           else if(nums[k]==a[j])
            {
                
                m=k;
            }
        }
        
          if(l>m)
              return {m,l};
      
	      else
            return{l,m};
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
