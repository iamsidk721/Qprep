#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
	    bool ans=true;
	    for(int i=0;i<str.length();i++)
	    {
	        if(str[i]=='{' or str[i]=='(' or str[i]=='[')
	        {
	            s.push(str[i]);
	        }
	        else
	        {
	            if(str[i]=='}')
	            {
	                if(!s.empty() and s.top()=='{')
	                {
	                    s.pop();
	                }
	                else if(!s.empty() and s.top()!='{')
	                {
	                    ans=false;
	                    break;
	                }
	                else if(s.empty())
	                {
	                    ans=false;
	                    break;
	                }
	            }
	            else if(str[i]==')')
	            {
	                if(!s.empty() and s.top()=='(')
	                {
	                    s.pop();
	                }
	                else if(!s.empty() and s.top()!='(')
	                {
	                    ans=false;
	                    break;
	                }
	                else if(s.empty())
	                {
	                    ans=false;
	                    break;
	                }
	            }
	            else if(str[i]==']')
	            {
	                if(!s.empty() and s.top()=='[')
	                {
	                    s.pop();
	                }
	                else if(!s.empty() and s.top()!='[')
	                {
	                    ans=false;
	                    break;
	                }
	                else if(s.empty())
	                {
	                    ans=false;
	                    break;
	                }
	            }
	        }
	    }
	    if(!s.empty())
	    {
	        ans=false;
	    }
        return ans;
    }
};
int main() {
	FastIO();
	string s;
	getline(cin, s);
	bool result = ValidParenthesis().isValid(s);
	cout << boolalpha << result;
	return 0;
}
