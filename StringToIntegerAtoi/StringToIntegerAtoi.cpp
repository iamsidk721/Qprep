#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include <sstream>
using namespace std;

class StringToIntegerAtoi {
public:
    // Implement your solution by completing the below function	
    int myAtoi(string str) {
		int f=0,x=str.size();
		for(int i=0;i<x;i++)
		{
			if(isdigit(str[i]))
			{
			f=1;	
			}
		}
		if(f==1)
		{int ans = stoi(str);
        return ans;}
		else
		return 0;
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
