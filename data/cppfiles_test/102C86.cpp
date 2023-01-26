#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15, mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long test;
  cin >> test;
  while (test--) {
    long long n, m, i, ln;
    cin >> n >> m;
    string s;
    cin >> s;
    ln = s.length();
    vector<long long> lr(ln), ud(ln);
    if (s[0] == 'L') lr[0] = -1;
    if (s[0] == 'R') lr[0] = 1;
    if (s[0] == 'D') ud[0] = -1;
    if (s[0] == 'U') ud[0] = 1;
    for (i = 1; i < ln; i++) {
      lr[i] = lr[i - 1];
      ud[i] = ud[i - 1];
      if (s[i] == 'L') lr[i] += -1;
      if (s[i] == 'R') lr[i] += 1;
      if (s[i] == 'D') ud[i] += -1;
      if (s[i] == 'U') ud[i] += 1;
    }
    if ((m == 1 && lr[0] != 0) || (n == 1 && ud[0] != 0)) {
      cout << "1 1\n";
      continue;
    }
    long long l = 0, r = 0, u = 0, d = 0;
    for (i = 0; i < ln - 1; i++) {
      l = min(l, lr[i]);
      r = max(r, lr[i]);
      d = min(d, ud[i]);
      u = max(u, ud[i]);
      if (!(-min(l, lr[i + 1]) + max(r, lr[i + 1]) + 1 <= m &&
            -min(d, ud[i + 1]) + max(u, ud[i + 1]) + 1 <= n))
        break;
    }
    l = min(l, lr[i]);
    u = max(u, ud[i]);
    cout << u + 1 << ' ' << -l + 1 << '\n';
  }
}
