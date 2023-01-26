#include <bits/stdc++.h>
using namespace std;
struct N {
  vector<int> v;
} p;
vector<int> v;
map<int, struct N> mp;
int t, n, m, a, now, u, w[100010];
int f[100010];
long long ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    mp.clear();
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a);
        if (!mp.count(a)) mp[a] = p;
        mp[a].v.push_back((i - 1) * m + j);
      }
    ans = 0;
    now = 1;
    u = 1;
    memset(f, 0, (n * m + 1) * sizeof(int));
    for (auto it = mp.begin(); it != mp.end(); it++) {
      v = it->second.v;
      if (v.size() <= (m - u + 1)) {
        for (int i = v.size() - 1; i >= 0; i--) {
          w[v[i]] = (now - 1) * m + u;
          u++;
        }
        if (u > m) {
          u = 1;
          now++;
        }
      } else {
        int k = v.size() - 1, l = 0, r = l + m - u;
        while (r <= k) {
          for (int i = r; i >= l; i--) {
            w[v[i]] = (now - 1) * m + u;
            u++;
          }
          now++;
          u = 1;
          l = r + 1;
          r = l + m - u;
        }
        for (int i = k; i >= l; i--) {
          w[v[i]] = (now - 1) * m + u;
          u++;
        }
      }
    }
    for (int i = 1; i <= n * m; i++) {
      int l = w[i] / m + (w[i] % m != 0), r = (w[i] % m == 0 ? m : w[i] % m);
      for (int i = 1; i < r; i++)
        if (f[(l - 1) * m + i]) {
          ans++;
        }
      f[(l - 1) * m + r] = 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
