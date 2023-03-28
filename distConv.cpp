// 간단한 이산합성곱

#include <iostream>
#include <vector>

using namespace std;

vector<int> conv(vector<int> v1, vector<int> v2) {
	vector<int> res;
	for (int i = 0; i < v1.size() + v2.size() - 1;i++) {
		int tmp = 0;
		for (int j = 0; j < v1.size(); j++) {
			if (i - j >= 0 && i - j < v2.size()) {
				tmp += v1[j] * v2[i-j];	
			}  
		}
		res.push_back(tmp);
	}
	return res;
}

int main() {
	vector<int> v1 = {1,2,3,5,10};
	vector<int> v2 = {1,5};
	vector<int> res = conv(v1, v2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	return 0;
}
