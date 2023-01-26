#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int n;
bool a[N][7];
unordered_map<int, bool> cnt[7];
void solve() {
  cin >> n;
  for (int i = 1; i <= 5; i++) {
    cnt[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> a[i][j];
      if (a[i][j]) {
        cnt[j][i] = 1;
      }
    }
  }
  for (int i = 1; i <= 5; i++) {
    for (int j = i + 1; j <= 5; j++) {
      if (cnt[i].size() == 0 || cnt[j].size() == 0) {
        continue;
      }
      int d1 = 0, d2 = 0, dak = 0;
      for (auto &x : cnt[i]) {
        if (cnt[j].count(x.first)) {
          dak++;
        } else
          d1++;
      }
      d2 = (int)cnt[j].size() - dak;
      if (n / 2 - d1 + n / 2 - d2 <= dak) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
signed main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
