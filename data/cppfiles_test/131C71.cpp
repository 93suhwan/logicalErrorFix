#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void fileio(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long INF = 4e18;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return (flag ? x : ~(x - 1));
}
long long n, res;
array<long long, 2> ans;
map<long long, array<long long, 2>> mp;
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) mp[read()] = {0, i};
  long long x = INF;
  while (1) {
    auto it = --mp.lower_bound(x);
    x = it->first;
    if (!x) break;
    long long fa;
    for (long long i = 0; i < 31; i++)
      if ((1 << i) >= x) {
        fa = (1 << i) - x;
        break;
      }
    if (mp.find(fa) == mp.end()) mp[fa] = {-INF, 0};
    if (mp[fa][0] + it->second[0] + 1 > res) {
      res = mp[fa][0] + it->second[0] + 1;
      ans = {mp[fa][1], it->second[1]};
    }
    mp[fa] = max(mp[fa], {it->second[0] + 1, it->second[1]});
  }
  cout << ans[0] << " " << ans[1] << " " << res;
  return 0;
}
