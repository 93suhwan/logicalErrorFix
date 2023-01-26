#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline void solve(vector<int>& nums) {
  int n = nums.size();
  int s = 0;
  for (int num : nums) s += num;
  if (s % n == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      nums.push_back(num);
    }
    solve(nums);
  }
  return 0;
}
