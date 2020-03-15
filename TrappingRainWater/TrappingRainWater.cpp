#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
using namespace std;

class TrappingRainWater {
public:
    int trap(vector<int>& height) {
        int white = 0;
        int mx = 0;
        for(int i = 0; i < height.size(); i ++) {
            if(height[i] > mx) {
                white += (height[i] - mx) * i;
                mx = height[i];
            }
        }
        mx = 0;
        for(int i = height.size() - 1; i >=0 ; i --) {
            if(height[i] > mx) {
                white += (height[i] - mx) * (height.size() - 1 - i);
                mx = height[i];
            }
        }
        int total = mx * height.size();
        int black = 0;
        for(int i = 0; i < height.size(); i ++) {
            black += height[i];
        }
        int ans = total - white - black;
        return ans;
    }
};

int main() {
	FastIO();
	int n;
	cin >> n;
	vector<int> heights;
	ReadMatrix<int>().OneDMatrix(n, heights);
	int result = TrappingRainWater().trap(heights);
	cout << result;
	return 0;
}
