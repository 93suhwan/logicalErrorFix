#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long f[200007 << 1], ans[200007 << 1], tot;
long long find(long long x) {
  if (f[x] == x)
    return x;
  else
    return f[x] = find(f[x]);
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    tot = 0;
    for (long long i = 1; i <= 2 * n; i++) {
      f[i] = i, ans[i] = 0;
    }
    for (long long z = 1; z <= m; z++) {
      long long x, y;
      string s;
      cin >> x >> y >> s;
      if (s == "imposter") {
        f[find(x)] = find(y + n);
        f[find(x + n)] = find(y);
      } else {
        f[find(x)] = find(y);
        f[find(x + n)] = find(y + n);
      }
    }
    bool flag = true;
    for (long long i = 1; i <= n; i++) {
      if (find(i) == find(i + n)) flag = false;
    }
    if (!flag) {
      cout << "-1" << endl;
      continue;
    }
    for (long long i = 1; i <= n; i++) ans[find(i)]++;
    for (long long i = 1; i <= n; i++) {
      if (f[i] == i || f[i + n] == i + n) tot += max(ans[i], ans[i + n]);
    }
    cout << tot << endl;
  }
  return 0;
}
