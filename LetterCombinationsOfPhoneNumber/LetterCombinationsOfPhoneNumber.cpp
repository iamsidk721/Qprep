#include <bits/stdc++.h>
#include <iostream>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class LetterCombinationsOfPhoneNumber {
    public:
        void get_combination_backtrack( string digits_letter_combination_map[], vector<string>& final_result_set, string& local_storage, int index, string& digits) 
{   int x=digits.size();
     int y=digits_letter_combination_map[digits[index]-'0'].size();
        if(index==x)
            final_result_set.push_back(local_storage);
        else
            for(int i=0;i<y;i++) 
            {
                local_storage.push_back(digits_letter_combination_map[digits[index]-'0'][i]);
                get_combination_backtrack(digits_letter_combination_map, final_result_set, local_storage, index+1, digits);
                local_storage.pop_back();
            }
}


vector<string> letterCombinations(string digits) 
{
	vector<string> final_result_set;
    string digits_letter_combination_map [10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string local_storage;

    get_combination_backtrack(digits_letter_combination_map, final_result_set,local_storage, 0, digits);

    return final_result_set;
}
    };

int main() {
	FastIO();
	string digits;
	cin >> digits;
	vector<string> combinations = LetterCombinationsOfPhoneNumber().letterCombinations(digits);
	PrintMatrix<string>().OneDMatrix(combinations, " ");
	return 0;
}
