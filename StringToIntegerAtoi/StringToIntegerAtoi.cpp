#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include <sstream>
using namespace std;

class StringToIntegerAtoi {
public:
    // Implement your solution by completing the below function	
    int myAtoi(string str) {
		int x=str.size();
		for(int i=0;i<x;i++)
		{
			if(isdigit(str[i]))
			{
              int ans = stoi(str);
              return ans;
              break;
			}
			else
			{
				return 0;
				break;
			}
			
		}
		
    }
};

int main() {
	FastIO();
	string str;
	cin >> str;
	int result = StringToIntegerAtoi().myAtoi(str);
	cout << result;
	return 0;
}
