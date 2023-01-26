#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
long long n = 200001;
class Solution {
 public:
  vector<vector<int>> arr;
  void precalculate() {
    this->arr = vector<vector<int>>(n, vector<int>(20, 0));
    for (int i = 1; i < n; ++i) {
      int num = i;
      int k = 0;
      while (num > 0) {
        arr[i][k] = arr[i - 1][k] + (num & 1);
        num = num >> 1;
        ++k;
      }
    }
  }

 public:
  int solve(int start, int end) {
    int max_offsets = 0;
    for (int i = 0; i < 20; ++i) {
      max_offsets = max(max_offsets, arr[end][i] - arr[start - 1][i]);
    }
    return (end - start + 1 - max_offsets);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  Solution s = Solution();
  s.precalculate();
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << s.solve(l, r) << endl;
  }
  return 0;
}
