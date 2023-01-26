#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) a[i + 1] = s[i] == '+' ? 1 : -1;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] + (i & 1 ? 1 : -1) * a[i];
    while (q--) {
      int l, r;
      cin >> l >> r;
      int s = abs(pref[r] - pref[l - 1]);
      if (s == 0)
        cout << 0 << '\n';
      else
        cout << min(s, 2 - (s & 1)) << '\n';
    }
  }
  return 0;
}
