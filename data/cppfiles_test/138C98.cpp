#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 2e5 + 5;
int n, m, q;
pair<long long, long long> k[N], ans[N];
long long a[N], b[N];
long long f[N << 1], s[N << 1];
set<long long> s1;
set<pair<long long, long long> > s2;
long long get(int l, int r) {
  long long x = s[r] - s[l];
  return f[r] - f[r - x];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  for (int i = 1; i <= q; ++i) {
    cin >> k[i].first;
    k[i].second = i;
  }
  sort(k + 1, k + 1 + q);
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  int d = 0;
  int i = 1, j = 1;
  while (i <= n || j <= m) {
    if (i > n) {
      f[++d] = b[j];
      j++;
      continue;
    }
    if (j > m) {
      f[++d] = a[i];
      s[d] = 1;
      i++;
      continue;
    }
    if (a[i] <= b[j]) {
      f[++d] = a[i];
      s[d] = 1;
      i++;
    } else {
      f[++d] = b[j];
      j++;
    }
  }
  s1.insert(0);
  s2.insert(pair<long long, long long>(1e10, 0));
  s1.insert(n + m);
  s2.insert(pair<long long, long long>(1e10, n + m));
  for (int i = 1; i <= d - 1; ++i) {
    s1.insert(i);
    s2.insert(pair<long long, long long>(f[i + 1] - f[i], i));
  }
  for (int i = 1; i <= d; ++i) {
    f[i] += f[i - 1];
    s[i] += s[i - 1];
  }
  for (int i = 1; i <= n; ++i) ans[0].second += a[i];
  for (int i = 1; i <= q; ++i) {
    long long x = k[i].first;
    ans[i] = pair<long long, long long>(k[i].second, ans[i - 1].second);
    while (!s2.empty()) {
      auto it = s2.begin();
      if ((*it).first > k[i].first) break;
      auto l = s1.lower_bound((*it).second);
      l--;
      ans[i].second -= get(*l, (*it).second);
      auto r = s1.upper_bound((*it).second);
      ans[i].second -= get((*it).second, *r);
      ans[i].second += get(*l, *r);
      auto it2 = s1.find((*it).second);
      s1.erase(it2);
      s2.erase(it);
    }
  }
  sort(ans + 1, ans + 1 + q);
  for (int i = 1; i <= q; ++i) cout << ans[i].second << '\n';
}
