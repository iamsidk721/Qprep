#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include <sstream>
using namespace std;

class StringToIntegerAtoi {
public:
    // Implement your solution by completing the below function	
    int myAtoi(string str) {
		int ans = stoi(str),f=0;
        for(int i=0;i<str.size();i++)
		{
		if(str[i]=='-')
		f=1;}
		if(f==1)
		ans=ans*(-1);
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
