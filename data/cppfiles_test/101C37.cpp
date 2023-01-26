#include <bits/stdc++.h>
using namespace std;
signed main() {
  int64_t tt;
  cin >> tt;
  while (tt--) {
    int64_t n;
    cin >> n;
    int64_t a[n];
    for (int64_t i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    vector<int64_t> r, b;
    for (int64_t i = 0; i < n; i++) {
      if (s[i] == 'B')
        b.push_back(a[i]);
      else
        r.push_back(a[i]);
    }
    sort(b.begin(), b.end()), sort(r.begin(), r.end());
    int64_t m = 1;
    bool p = 1;
    for (int64_t i = 0; i < b.size(); i++, m++)
      if (b[i] < m) p = 0;
    for (int64_t i = 0; i < r.size(); i++, m++)
      if (r[i] > m) p = 0;
    puts(p ? "YES" : "NO");
  }
}
