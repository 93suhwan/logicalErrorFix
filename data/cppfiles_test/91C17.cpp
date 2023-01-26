#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 100010;
vector<pair<int, int>> v[2];
int a[maxn];
int main() {
  int t;
  scanf("%d", &t);
  int n, cur;
  long long ans, tmp;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    ans = cur = 0, v[cur].clear();
    for (int i = n; i; i--) {
      v[cur ^= 1].clear();
      for (auto& j : v[cur ^ 1]) {
        tmp = (a[i] - 1) / j.first;
        ans = (ans + tmp * j.second % mod * i) % mod;
        if (!v[cur].empty() && a[i] / (tmp + 1) == v[cur].rbegin()->first)
          v[cur].rbegin()->second += j.second;
        else
          v[cur].emplace_back(a[i] / (tmp + 1), j.second);
      }
      if (!v[cur].empty() && a[i] == v[cur].rbegin()->first)
        v[cur].rbegin()->second++;
      else
        v[cur].emplace_back(a[i], 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
