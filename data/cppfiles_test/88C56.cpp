#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
void input_misc() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
void run_case() {
  int N;
  cin >> N;
  vector<int> nums(N, 0);
  for (auto& val : nums) {
    cin >> val;
  }
  str res = "YES";
  if (N & 1) {
    bool flag = false;
    for (int i = 0; i < N - 1; i += 1) {
      flag = flag or (nums[i] >= nums[i + 1]);
    }
    if (not flag) {
      res = "NO";
    }
  }
  cout << res << "\n";
}
int main() {
  input_misc();
  int N;
  cin >> N;
  while (N-- > 0) {
    run_case();
  }
}
