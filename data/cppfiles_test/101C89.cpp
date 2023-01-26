#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int64_t cases = 1;
  cin >> cases;
  while (cases--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<char, int>> b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) b[i] = {s[i], a[i]};
    sort(b.begin(), b.end());
    int64_t i = 0, freee = 1;
    bool ok = 1;
    while (b[i].first == 'B') {
      if (b[i].second < freee)
        ok = 0;
      else
        freee++;
      ++i;
    }
    int64_t ii = n - 1;
    freee = n;
    while (b[ii].first == 'R') {
      if (b[ii].second > freee)
        ok = 0;
      else
        freee--;
      --ii;
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
