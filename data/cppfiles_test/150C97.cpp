#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    int n;
    cin >> n;
    vector<int> a(n);
    int coins = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto check = [&](int one, int two, int val) -> int {
      vector<int> combination;
      for (int i = 0; i <= one; i++) {
        for (int j = 0; j <= two; j++) {
          combination.emplace_back(i + 2 * j);
        }
      }
      int cur_coins = 1e9 + 7;
      for (int i : combination) {
        if ((val < i) or (val - i) % 3 != 0) continue;
        cur_coins = min(cur_coins, (val - i) / 3);
      }
      return cur_coins + one + two;
    };
    for (int one = 0; one < 3; one++) {
      for (int two = 0; two < 3; two++) {
        int cur = 0;
        for (int i : a) {
          cur = max(cur, check(one, two, i));
        }
        coins = min(coins, cur);
      }
    }
    cout << coins << '\n';
  }
  return 0;
}
