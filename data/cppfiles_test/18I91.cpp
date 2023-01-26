#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int n, d, f = 0;
    cin >> n >> d;
    vector<int> a(n), temp(n), ans(n, 1e9);
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
      temp[i] = a[(i - d + n) % n];
      if (a[i]) f = 1;
    }
    if (temp == a && f) {
      cout << "-1\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (!a[i]) ans[i] = 0;
    }
    int cnt = 3;
    while (cnt--) {
      for (int i = 0; i < n; i++) {
        ans[i] = min(ans[i], ans[(i - d + n) % n] + 1);
      }
    }
    int mnm = 0;
    for (int i = 0; i < n; i++) {
      mnm = max(mnm, ans[i]);
    }
    cout << mnm << "\n";
  }
}
