#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 1e6, Mod = 1e9 + 7;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long n, k, s, col[26];
long long f[Maxn + 5][7], vis[Maxn + 5], ch[Maxn + 5][2];
vector<pair<long long, long long> > v;
vector<long long> q;
inline void Init() {
  col['w' - 'a'] = 1;
  col['y' - 'a'] = 2;
  col['g' - 'a'] = 3;
  col['b' - 'a'] = 4;
  col['r' - 'a'] = 5;
  col['o' - 'a'] = 6;
}
inline long long Pow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % Mod;
    x = 1ll * x * x % Mod, y >>= 1;
  }
  return res;
}
inline long long Get(long long x) {
  return lower_bound(q.begin(), q.end(), x) - q.begin() + 1;
}
inline void dfs(long long x) {
  if (!ch[x][0]) {
    f[x][vis[x]] = 1;
    return;
  }
  if (ch[x][0]) dfs(ch[x][0]);
  if (ch[x][1]) dfs(ch[x][1]);
  for (long long i = (1); i <= (6); ++i) {
    if (vis[x] > 0 && i != vis[x]) continue;
    long long a1 = 0, a2 = 0;
    if (ch[x][0])
      for (long long j = (1); j <= (6); ++j)
        if ((i + 1) / 2 != (j + 1) / 2) a1 = (a1 + f[ch[x][0]][j]) % Mod;
    if (ch[x][1])
      for (long long j = (1); j <= (6); ++j)
        if ((i + 1) / 2 != (j + 1) / 2) a2 = (a2 + f[ch[x][1]][j]) % Mod;
    if (!ch[x][1])
      f[x][i] = a1;
    else
      f[x][i] = a1 * a2 % Mod;
  }
}
signed main() {
  Init();
  cin >> n >> k;
  s = (1ll << n) - 1ll;
  for (long long i = (1); i <= (k); ++i) {
    long long a;
    string b;
    cin >> a >> b;
    v.push_back(make_pair(a, col[b[0] - 'a']));
  }
  q.push_back(1);
  for (auto i : v) {
    long long a = i.first;
    while (a) q.push_back(a), a /= 2;
  }
  sort(q.begin(), q.end()), q.erase(unique(q.begin(), q.end()), q.end());
  for (auto i : v) {
    long long a = i.first, b = i.second, ma = a;
    while (1) {
      long long c = Get(a), d = Get(a / 2);
      if (vis[c] != 0) break;
      vis[c] = -1;
      if (a == 1) break;
      if (!ch[d][0])
        ch[d][0] = c;
      else
        ch[d][1] = c;
      a /= 2;
    }
    vis[Get(ma)] = b;
  }
  dfs(1);
  long long all = 0;
  for (long long i = (1); i <= (6); ++i) all = (all + f[1][i]) % Mod;
  long long siz = q.size();
  siz = s - siz;
  cout << all * Pow(4, siz) % Mod << endl;
  return 0;
}
