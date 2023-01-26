#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
class Solution {
 public:
  int solve(const int start, const int end) {
    int count = 0;
    int curr = INT_MAX;
    for (int i = start; i <= end; ++i) {
      int next = curr & i;
      if (next == 0) {
        ++count;
      } else {
        curr = next;
      }
    }
    int count2 = 0;
    curr = INT_MAX;
    for (int i = end; i >= start; --i) {
      int next = curr & i;
      if (next == 0) {
        ++count2;
      } else {
        curr = next;
      }
    }
    return min(count, count2);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << Solution().solve(l, r) << endl;
  }
  return 0;
}
