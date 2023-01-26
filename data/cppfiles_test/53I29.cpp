#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto solve = [&]() {
      if (k >= 3) return 1;
      if (k == 1) {
        for (int i = 0; i < n - 1; ++i)
          if (a[i] > a[i + 1]) return 0;
        return 1;
      }
      if (k == 2) {
        for (int i = 0; i < n - 1; ++i)
          if (a[i] > a[i + 1]) {
            for (int j = i + 1; i < n - 1; ++j)
              if (a[j] > a[j + 1] || a[j] > a[0]) return 0;
            return 1;
          }
        return 1;
      }
    };
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
