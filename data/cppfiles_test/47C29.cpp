#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int getSum(int x, int y) {
  int tmp, res = 0;
  cout << "and " << x << " " << y << endl;
  cin >> tmp;
  res += tmp;
  cout << "or " << x << " " << y << endl;
  cin >> tmp;
  res += tmp;
  return res;
}
int main() {
  int n, k;
  cin >> n >> k;
  int a12 = getSum(1, 2);
  int a23 = getSum(2, 3);
  int a13 = getSum(1, 3);
  int a = (a12 + a13 - a23) / 2;
  nums.push_back(a);
  nums.push_back(a12 - a);
  nums.push_back(a13 - a);
  for (int i = 4; i <= n; ++i) {
    int tmp = getSum(1, i);
    nums.push_back(tmp - a);
  }
  sort(nums.begin(), nums.end(), [](int x, int y) { return x < y; });
  cout << "finish " << nums[k - 1] << endl;
  return 0;
}
