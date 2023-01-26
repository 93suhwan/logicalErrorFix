#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int inf = 1e9;
int mod = 998244353;
inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += mod;
}
inline int mul(int a, int b) { return (int)((long long)a * b % mod); }
inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
inline int inv(int a) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}
int get(int i, int j) { return ((i & 1) ^ (j & 1)); }
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  map<int, int> rset[n + 1], cset[m + 1];
  map<pair<int, int>, int> val;
  map<int, int> ov;
  int badr = 0, badc = 0;
  int cntr = 0, cntc = 0;
  for (int i = 0; i < k; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    if ((int)rset[x].size() > 1) badr--;
    if ((int)cset[y].size() > 1) badc--;
    if (!rset[x].empty()) cntr--;
    if (!cset[y].empty()) cntc--;
    if (val.find({x, y}) != val.end()) {
      int cc = val[{x, y}];
      int rg = get(y, cc);
      int cg = get(x, cc);
      rset[x][rg]--;
      if (!rset[x][rg]) rset[x].erase(rset[x].find(rg));
      cset[y][cg]--;
      if (!cset[y][cg]) cset[y].erase(cset[y].find(cg));
      val.erase(val.find({x, y}));
      int og = get(x + y, cc);
      ov[og]--;
      if (!ov[og]) ov.erase(ov.find(og));
    }
    if (c != -1) {
      val[{x, y}] = c;
      rset[x][get(y, c)]++;
      cset[y][get(x, c)]++;
      int og = get(x + y, c);
      ov[og]++;
    }
    if ((int)rset[x].size() > 1) badr++;
    if ((int)cset[y].size() > 1) badc++;
    if (!rset[x].empty()) cntr++;
    if (!cset[y].empty()) cntc++;
    if (badr && badc)
      cout << "0\n";
    else if (!badr && badc)
      cout << power(2, n - cntr) << "\n";
    else if (badr)
      cout << power(2, m - cntc) << "\n";
    else {
      int ans = power(2, n - cntr);
      add(ans, power(2, m - cntc));
      if (cntr + cntc) {
        if (ov.size() == 1) sub(ans, 1);
      } else
        sub(ans, 2);
      cout << ans << "\n";
    }
  }
  return 0;
}
