#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> vec;
	vec.reserve(10);
	vec[2] = 2;
	cout << vec[2] << endl;
	return 0;
}
