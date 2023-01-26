#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch = getchar();
  x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
const long long N = 402;
long long n, k, c[N], vis[N];
long long pw[50], s[N];
vector<long long> a[N];
vector<long long> now, nxt, cur;
unordered_map<long long, long long> mp;
signed main() {
  read(n), read(k);
  pw[0] = mp[0] = 1;
  for (long long i = 1; i <= 45; ++i) pw[i] = pw[i - 1] * 2;
  for (long long i = n - 1, tmp = 0; i >= 0; --i) tmp |= pw[i], mp[tmp] = 1;
  for (long long i = 1; i <= k; ++i) {
    read(c[i]);
    for (long long j = 1, x; j <= c[i]; ++j) read(x), a[i].push_back(x - 1);
    reverse(a[i].begin(), a[i].end());
  }
  if (n == 1) return puts("ACCEPTED"), 0;
  now.push_back(0);
  for (long long i = 1; i <= k; ++i) {
    long long num = 0, tmp = 0;
    for (long long x : a[i]) {
      if (!vis[x]) ++num;
      s[++tmp] = s[tmp - 1] | pw[x];
      if (tmp > 40) {
        printf("%d\n", c[i]);
        for (long long y : a[i]) printf("%d ", y);
        puts("");
        return 0;
      }
    }
    nxt.clear();
    for (long long x : now) {
      long long p = x & s[tmp], cc = __builtin_popcount(p);
      for (long long j = 0; j <= num; ++j) {
        nxt.push_back((x ^ p) | s[cc + j]);
      }
    }
    for (long long x : a[i]) vis[x] = 1;
    now = nxt;
  }
  for (long long i = 0; i < n; ++i)
    if (!vis[i]) return puts("REJECTED"), 0;
  long long tag = 1, ss = 0;
  for (long long x : now)
    if (!mp.count(x)) {
      tag = 0;
      break;
    }
  puts(tag ? "ACCEPTED" : "REJECTED");
  return 0;
}
