#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class LetterCombinationsOfPhoneNumber {
public:
    // Implement your solution by completing the below function
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
        cout<<"chars = "<<chs<<endl;
        cout<<"digits[i] = "<<digits[i]<<endl;
        cout<<"digits[i] - '0' = "<<digits[i] - '0'<<endl;


        for (int c = 0; c < y;c++)
        {
            for (int j = 0; j < z;j++)
            {
                cout<<"res[j]= "<<res[j]<<endl;
                cout<<"chars[c]= "<<chs[c]<<endl;
                cout<<"res[j]+chars[c]= "<<res[j]+chs[c]<<endl;


                tempres.push_back(res[j]+chs[c]);
            }
            cout<<endl;
        }
        res = tempres;
    }
        return res;
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
