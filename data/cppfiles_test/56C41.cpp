#include <bits/stdc++.h>
using namespace std;
const int N = 2000 * 60 + 10, mod = 1e9 + 7;
int k, n;
long long cnt;
int color[N];
map<long long, int> id;
long long f[N][8];
long long qmi(long long a, long long k, long long p) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * a % p;
    k >>= 1;
    a = a * a % p;
  }
  return res;
}
void dfs(long long u) {
  if (id[u << 1]) dfs(u << 1);
  if (id[u << 1 | 1]) dfs(u << 1 | 1);
  int k = id[u], l = id[u << 1], r = id[u << 1 | 1];
  if (color[k]) {
    for (int i = 2; i <= 7; i++)
      if (i != color[k]) f[k][i] = 0;
    long long left = 1, right = 1;
    if (l) {
      left = 0;
      for (int i = 2; i <= 7; i++)
        if (i != color[k] && (i ^ color[k]) != 1) left = (left + f[l][i]) % mod;
    }
    if (r) {
      right = 0;
      for (int i = 2; i <= 7; i++)
        if (i != color[k] && (i ^ color[k]) != 1)
          right = (right + f[r][i]) % mod;
    }
    f[k][color[k]] = left * right % mod;
  } else {
    for (int i = 2; i <= 7; i++) {
      long long left = 1, right = 1;
      if (l) {
        left = 0;
        for (int j = 2; j <= 7; j++)
          if (j != i && (j ^ i) != 1) left = (left + f[l][j]) % mod;
      }
      if (r) {
        right = 0;
        for (int j = 2; j <= 7; j++)
          if (j != i && (j ^ i) != 1) right = (right + f[r][j]) % mod;
      }
      f[k][i] = left * right % mod;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> n;
  for (int i = 1; i <= n; i++) {
    long long v;
    string s;
    cin >> v >> s;
    if (!id.count(v)) id[v] = ++cnt;
    if (s == "white")
      color[id[v]] = 2;
    else if (s == "yellow")
      color[id[v]] = 3;
    else if (s == "green")
      color[id[v]] = 4;
    else if (s == "blue")
      color[id[v]] = 5;
    else if (s == "red")
      color[id[v]] = 6;
    else
      color[id[v]] = 7;
    v >>= 1;
    while (v) {
      if (!id.count(v))
        id[v] = ++cnt;
      else
        break;
      v >>= 1;
    }
  }
  dfs(1);
  long long ans = 0;
  for (int i = 2; i <= 7; i++) ans = (ans + f[id[1]][i]) % mod;
  cnt = (1ll << k) - 1 - cnt;
  cout << ans * qmi(4, cnt, mod) % mod << endl;
  return 0;
}
