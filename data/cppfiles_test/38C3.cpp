#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> f(m, 0);
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int j = 1; j < m; ++j) {
      bool blocked = false;
      for (int i = 1; i < n; ++i) {
        if (a[i][j - 1] == 'X' && a[i - 1][j] == 'X') blocked = true;
      }
      f[j] = (blocked == true);
      f[j] += f[j - 1];
    }
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      if (f[r] - f[l])
        cout << "NO" << '\n';
      else
        cout << "YES" << '\n';
    }
  }
  return 0;
}
