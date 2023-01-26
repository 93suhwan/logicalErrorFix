#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const char *colors = "wgroby";
map<long long, int> color;
set<long long> mark;
map<pair<long long, int>, int> dp;
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
long long power(long long a, long long b) {
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ret = ret * a % mod;
  return ret;
}
int solve(long long v, int c, long long z) {
  if (!mark.count(v)) {
    return power(4, z - 1);
  }
  if (color.count(v) && color[v] != c) {
    return 0;
  }
  if (z == 1) {
    return 1;
  }
  if (dp.count({v, c})) {
    return dp[{v, c}];
  }
  int x = 0, y = 0;
  for (int i = 0; i < 6; i++)
    if (i != c && i + c != 5) {
      add(x, solve(2 * v, i, z / 2));
      add(y, solve(2 * v + 1, i, z / 2));
    }
  return dp[{v, c}] = x * 1ll * y % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  while (n--) {
    long long v;
    string s;
    cin >> v >> s;
    color[v] = strchr(colors, s[0]) - colors;
    while (v) {
      mark.insert(v);
      v /= 2;
    }
  }
  int res = 0;
  for (int i = 0; i < 6; i++) {
    add(res, solve(1, i, (1ll << k) - 1));
  }
  cout << res << '\n';
  return 0;
}
