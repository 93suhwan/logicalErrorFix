#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& s : a) cin >> s;
  vector<int> pref(m);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j + 1] == 'X' and a[i + 1][j] == 'X') {
        pref[j + 1] += 1;
      }
    }
  }
  for (int i = 1; i < m; i++) {
    pref[i] += pref[i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << (pref[r] != pref[l] ? "NO" : "YES") << '\n';
  }
}
