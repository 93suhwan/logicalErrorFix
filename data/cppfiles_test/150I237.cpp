#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
int __FAST_IO__ = []() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  return 0;
}();
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> count(3, 0);
    int ans = 0, has3 = 0;
    for (int i = 0; i < (N); ++i) {
      cin >> v[i];
      count[v[i] % 3]++;
      if (v[i] == 3) has3++;
      ans = max(v[i] / 3, ans);
    }
    if (count[2] > 0 && count[1] > 0) {
      int c1 = 0, c22 = 0, c23 = 0, c24 = 0, c3 = 0;
      for (int i = 0; i < (N); ++i) {
        c1 = max(c1, v[i] / 3 + 2);
        if (v[i] == 1)
          c22 = c23 = c24 = 2e9;
        else if (v[i] % 3 == 1) {
          c22 = max(c22, v[i] / 3 + 1);
          c23 = max(c23, v[i] / 3 + 2);
          c24 = max(c24, v[i] / 3 + 3);
        } else if (v[i] % 3 == 2) {
          c22 = max(c22, v[i] / 3 + 2);
          c23 = max(c23, v[i] / 3 + 3);
          c24 = max(c24, max(has3 ? 1 : 0, v[i] / 3 - 2) + 4);
        } else {
          c22 = max(c22, v[i] / 3 + 2);
          c23 = max(c23, max(has3 ? 1 : 0, v[i] / 3 - 2) + 3);
          c24 = max(c24, max(has3 ? 1 : 0, v[i] / 3 - 2) + 4);
        }
        c3 = max(c3, v[i] / 3 + 2);
      }
      ans = min({c1, c22, c23, c24, c3});
    } else if (count[2] > 0 && count[1] == 0) {
      ans++;
    } else if (count[2] == 0 && count[1] > 0) {
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
