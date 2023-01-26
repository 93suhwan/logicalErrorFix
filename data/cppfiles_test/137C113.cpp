#include <bits/stdc++.h>
using namespace std;
long long rev(long long x) {
  if (x < 0) return -1;
  long long res = 0;
  while (x) {
    res = res * 2 + x % 2;
    x /= 2;
  }
  return res;
}
map<long long, bool> vis1, vis2;
queue<long long> Q1, Q2;
const long long M = 1e18 + 10;
signed main() {
  long long x, y;
  long long h1, h2;
  bool ans = 0;
  cin >> x >> y;
  Q1.push(x);
  Q2.push(y);
  while ((y % 2 || x == y) && ((!Q2.empty()) || (!Q1.empty()))) {
    if (!Q1.empty()) h1 = Q1.front(), Q1.pop();
    if (!Q2.empty()) h2 = Q2.front(), Q2.pop();
    if (vis1[h2] || vis2[h1]) {
      ans = 1;
      break;
    }
    if (h1 <= M / 2 && !vis1[h1]) {
      if (!vis1[rev(h1 * 2)] && rev(h1 * 2) != -1) Q1.push(rev(h1 * 2));
      if (!vis1[rev(h1 * 2 + 1)] && rev(h1 * 2 + 1) != -1)
        Q1.push(rev(h1 * 2 + 1));
    }
    if (!vis2[rev(h2)] && (h2 % 2)) Q2.push(rev(h2));
    if (!vis2[rev(h2) / 2] && (h2 % 2)) Q2.push(rev(h2) / 2);
    vis1[h1] = 1;
    vis2[h2] = 1;
  }
  puts(ans ? "Yes" : "No");
  return 0;
}
