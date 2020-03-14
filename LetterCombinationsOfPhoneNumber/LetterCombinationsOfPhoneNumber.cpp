#include <bits/stdc++.h>
#include <iostream>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;


        vector<string> letterCombinations(string digits) {
    	vector<string> res;
        string chmp[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		int x=digits.size();
		int z=res.size();

		for (int i = 0; i < x; i++)
        {
        vector<string> tempres;
        string chs = chmp[digits[i] - '0'];
		int y=chs.size();
   
        for (int c = 0; c < y;c++)
        {
            for (int j = 0; j < z;j++)
            { tempres.push_back(res[j]+chs[c]);
            }
           
        }
        res = tempres;
        }
        return res;
        }
  

int main() {
	FastIO();
	string digits;
	cin >> digits;
	vector<string> combinations = letterCombinations(digits);
	PrintMatrix<string>().OneDMatrix(combinations, " ");
	return 0;
}
