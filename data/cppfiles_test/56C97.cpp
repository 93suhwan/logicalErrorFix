#include <bits/stdc++.h>
using namespace std;
void print(bool n) {
  if (n)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';
}
const long long MOD = 1000000007;
long long add(long long x, long long y) {
  x += y;
  while (x >= MOD * MOD) x -= MOD * MOD;
  while (x < 0) x += MOD;
  return x;
}
long long sub(long long x, long long y) { return add(x, MOD - y); }
long long mul(long long x, long long y) { return (x * y) % MOD; }
long long binpow(long long x, long long y) {
  long long z = 1;
  while (y > 0) {
    if (y % 2 == 1) z = mul(z, x);
    x = mul(x, x);
    y /= 2;
  }
  return z;
}
struct cmp {
  bool operator()(long long l, long long r) { return l > r; }
};
long long k, n;
map<long long, array<long long, 6> > dp;
map<long long, long long> q;
set<long long, cmp> p;
array<long long, 4> t[6];
long long get(long long x, long long col) {
  long long level = k - (long long)log2(x) - 1;
  if (level == 0) return 1;
  long long z = binpow(2, (1ll << (level + 1)) - 4);
  long long l = 0, r = 0;
  if (dp.find(2 * x) != dp.end())
    for (long long i = 0; i < 4; i++) l += dp[2 * x][t[col][i]];
  else
    l = 4 * z;
  if (dp.find(2 * x + 1) != dp.end())
    for (long long i = 0; i < 4; i++) r += dp[2 * x + 1][t[col][i]];
  else
    r = 4 * z;
  while (l >= MOD) l -= MOD;
  while (r >= MOD) r -= MOD;
  return l * r % MOD;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  t[0] = {1, 2, 3, 4};
  t[1] = {0, 2, 3, 5};
  t[2] = {0, 1, 4, 5};
  t[3] = {0, 1, 4, 5};
  t[4] = {0, 2, 3, 5};
  t[5] = {1, 2, 3, 4};
  cin >> k >> n;
  while (n--) {
    long long x;
    string s;
    cin >> x >> s;
    p.insert(x);
    if (s[0] == 'o')
      q[x] = 0;
    else if (s[0] == 'w')
      q[x] = 1;
    else if (s[0] == 'g')
      q[x] = 2;
    else if (s[0] == 'b')
      q[x] = 3;
    else if (s[0] == 'y')
      q[x] = 4;
    else
      q[x] = 5;
  }
  while (!p.empty()) {
    long long x = *p.begin();
    p.erase(p.begin());
    if (x > 1) p.insert(x / 2);
    if (q.find(x) != q.end()) {
      for (long long i = 0; i < 6; i++) dp[x][i] = 0;
      dp[x][q[x]] = get(x, q[x]);
    } else {
      for (long long i = 0; i < 3; i++) {
        dp[x][i] = get(x, i);
      }
      dp[x][3] = dp[x][2];
      dp[x][4] = dp[x][1];
      dp[x][5] = dp[x][0];
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 6; i++) ans += dp[1][i];
  cout << ans % MOD;
  return 0;
}
