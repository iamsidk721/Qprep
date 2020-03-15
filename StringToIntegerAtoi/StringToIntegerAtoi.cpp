#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include <sstream>
using namespace std;

class StringToIntegerAtoi {
public:
    // Implement your solution by completing the below function	
    int myAtoi(string str) {
		int ans = stoi(str),x=str.size();
		if(x==0)
		return 0;
		else
        return ans;
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
