#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  char ch = getchar();
  x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
const int N = 42;
int n, k, c[N], vis[N];
long long pw[50], s[N];
vector<int> a[N];
vector<long long> now, nxt, cur;
unordered_map<int, int> mp;
signed main() {
  read(n), read(k);
  pw[0] = mp[0] = 1;
  for (int i = 1; i <= 45; ++i) pw[i] = pw[i - 1] * 2;
  for (int i = n - 1, tmp = 0; i >= 0; --i) tmp |= pw[i], mp[tmp] = 1;
  for (int i = 1; i <= k; ++i) {
    read(c[i]);
    for (int j = 1, x; j <= c[i]; ++j) read(x), a[i].push_back(x - 1);
    reverse(a[i].begin(), a[i].end());
  }
  if (n == 1) return puts("ACCEPTED"), 0;
  now.push_back(0);
  for (int i = 1; i <= k; ++i) {
    int num = 0, tmp = 0;
    for (int x : a[i]) {
      if (!vis[x]) ++num;
      s[++tmp] = s[tmp - 1] | pw[x];
    }
    nxt.clear();
    for (int x : now) {
      int p = x & s[tmp], cc = __builtin_popcount(p);
      for (int j = 0; j <= num; ++j) {
        nxt.push_back((x ^ p) | s[cc + j]);
      }
    }
    for (int x : a[i]) vis[x] = 1;
    now = nxt;
  }
  for (int i = 0; i < n; ++i)
    if (!vis[i]) return puts("REJECTED"), 0;
  int tag = 1, ss = 0;
  for (int x : now)
    if (!mp.count(x)) {
      tag = 0;
      break;
    }
  puts(tag ? "ACCEPTED" : "REJECTED");
  return 0;
}
