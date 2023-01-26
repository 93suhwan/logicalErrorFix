#include <bits/stdc++.h>
using namespace std;
int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--) {
    string second, t;
    cin >> second >> t;
    const int n = second.length();
    const int m = t.length();
    if (m > n) {
      puts("NO");
      continue;
    }
    bool ok = false;
    vector<int> store[26][2];
    for (int i = 0; i < n; ++i) {
      int c = second[i] - 'a';
      store[c][i & 1].push_back(i);
    }
    auto check = [&](int second) {
      for (int i = 1; i < m; ++i) {
        int c = t[i] - 'a';
        int sign = !(second & 1);
        if (((int)store[c][sign].size()) == 0) return 0;
        auto itr =
            upper_bound(store[c][sign].begin(), store[c][sign].end(), second);
        if (itr == store[c][sign].end()) return 0;
        second = *itr;
      }
      return ((n - second) & 1);
    };
    for (int i = 0; i < 2; ++i) {
      int c = t[0] - 'a';
      if (((int)store[c][i].size())) {
        ok |= check(store[c][i][0]);
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
