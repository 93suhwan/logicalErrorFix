#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<long long> power[N];
void solve() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  long long ans = n;
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    if (u > v) {
      if (power[v].empty()) ans--;
      power[v].push_back(u);
    } else {
      if (power[u].empty()) ans--;
      power[u].push_back(v);
    }
  }
  long long q;
  scanf("%lld", &q);
  while (q--) {
    long long tmp;
    scanf("%lld", &tmp);
    if (tmp == 1) {
      long long u, v;
      scanf("%lld%lld", &u, &v);
      if (u > v) {
        if (power[v].empty()) ans--;
        power[v].push_back(u);
      } else {
        if (power[u].empty()) ans--;
        power[u].push_back(v);
      }
    } else if (tmp == 2) {
      long long u, v;
      scanf("%lld%lld", &u, &v);
      if (u > v) {
        vector<long long>::iterator it =
            find(power[v].begin(), power[v].end(), u);
        if (it != power[v].end()) power[v].erase(it);
        if (power[v].empty()) ans++;
      } else {
        vector<long long>::iterator it =
            find(power[u].begin(), power[u].end(), v);
        if (it != power[u].end()) power[u].erase(it);
        if (power[u].empty()) ans++;
      }
    } else
      printf("%lld\n", ans);
  }
}
signed main() {
  solve();
  return 0;
}
