#include <bits/stdc++.h>
using namespace std;
const int N = 500010, mod = 1000000007;
int n, m;
int p[N], d[N], cnt[N], fc[N];
struct _q {
  int a, b, c;
} q[N];
int find(int x) {
  if (p[x] == x) return x;
  int root = find(p[x]);
  d[x] ^= d[p[x]];
  p[x] = root;
  return p[x];
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      d[i] = 0;
      cnt[i] = 1;
      fc[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      int a, b, c = 0;
      string s;
      cin >> a >> b >> s;
      if (s[0] == 'i') c = 1;
      q[i] = {a, b, c};
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      int t = q[i].c, a = q[i].a, b = q[i].b;
      int pa = find(a), pb = find(b);
      if (pa == pb) {
        if ((d[a] ^ d[b]) != t) {
          ans = -1;
          break;
        }
      } else {
        cnt[pb] += cnt[pa];
        cnt[pa] = 0;
        p[pa] = pb;
        d[pa] = d[a] ^ d[b] ^ t;
      }
    }
    if (ans == -1) {
      cout << ans << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      int fa = find(i);
      if (d[i]) fc[fa]++;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += max(fc[i], cnt[i] - fc[i]);
    }
    cout << ans << endl;
  }
}
