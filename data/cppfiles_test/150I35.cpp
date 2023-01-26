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
      int c1 = 0, c2 = 0, c3 = 0;
      for (int i = 0; i < (N); ++i) {
        c1 = max(c1, v[i] / 3 + 2);
        if (v[i] == 1)
          c2 = 2e9;
        else if (v[i] % 3 == 1)
          c2 = max(c2, v[i] / 3 + 1);
        else if (v[i] % 3 == 2)
          c2 = max(c2, v[i] / 3 + 2);
        else if (v[i] % 3 == 0) {
          if (v[i] >= 6)
            c2 = max(max(has3 ? 1 : 0, v[i] / 3 - 2) + 3, c2);
          else
            c2 = max(3, c2);
        }
        c3 = max(c3, v[i] / 3 + 2);
      }
      ans = min({c1, c2, c3});
    } else if (count[2] > 0 && count[1] == 0) {
      ans++;
    } else if (count[2] == 0 && count[1] > 0) {
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
