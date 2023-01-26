#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e5 + 10;
const long long MOD = 998244353;
using namespace std;
int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
int mul(int x, int y) { return x * 1LL * y % MOD; }
int sub(int x, int y) {
  x -= y;
  if (x < 0) x += MOD;
  return x;
}
int poow(int x, int y) {
  if (y == 0) return 1;
  int ret = poow(x, y / 2);
  ret = mul(ret, ret);
  if (y & 1) ret = mul(ret, x);
  return ret;
}
int fact[50], inv[50];
void init() {
  fact[0] = 1;
  for (int i = 1; i < 50; i++) {
    fact[i] = mul(i, fact[i - 1]);
  }
  for (int i = 0; i < 50; i++) {
    inv[i] = poow(fact[i], MOD - 2);
  }
}
int C(int x, int y) {
  if (y > x) return 0;
  return mul(fact[x], mul(inv[y], inv[x - y]));
}
int n, cnt[23][27], pw[25];
char str[KL];
string t;
int dp[2][(1 << 23)];
int d[(1 << 23)], c[(1 << 23)];
vector<pair<int, int>> vec[26];
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 23; i++) pw[i] = 2 * pw[i - 1];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    t = str;
    for (int j = 0; j < t.size(); j++) {
      cnt[i][t[j] - 'a']++;
    }
  }
  for (int i = 0; i < 26; i++) {
    vec[i].push_back({-1, -1});
    for (int j = 0; j < n; j++) {
      vec[i].push_back({cnt[j][i], j});
    }
    sort(vec[i].begin(), vec[i].end());
  }
  dp[0][pw[n] - 1] = 1;
  for (int i = 0; i < 26; i++) {
    for (int mask = 1; mask < pw[n]; mask++) {
      if (dp[0][mask] == 0) continue;
      int nwmask = mask;
      for (int j = 1; j < vec[i].size(); j++) {
        dp[1][nwmask] =
            add(dp[1][nwmask],
                mul(vec[i][j].first - vec[i][j - 1].first, dp[0][mask]));
        if ((nwmask & pw[vec[i][j].second])) nwmask ^= pw[vec[i][j].second];
      }
    }
    for (int mask = 1; mask < pw[n]; mask++) {
      dp[0][mask] = dp[1][mask];
      dp[1][mask] = 0;
    }
  }
  int sum = 0;
  for (int mask = 0; mask < pw[n]; mask++)
    c[mask] = dp[0][mask], sum = add(sum, c[mask]);
  for (int j = 0; j < n; j++) {
    for (int mask = 0; mask < pw[n]; mask++) {
      if ((mask & pw[j])) c[mask] = add(c[mask], c[mask ^ pw[j]]);
    }
  }
  long long ans = 0;
  for (int mask = 1; mask < pw[n]; mask++) {
    int nwmask = 0;
    for (int j = 0; j < n; j++)
      if (!(mask & pw[j])) nwmask ^= pw[j];
    int val = sub(sum, c[nwmask]);
    long long pr = 0, cnt = 0;
    for (int j = 0; j < n; j++) {
      if ((mask & pw[j])) pr += (long long)(j + 1), cnt++;
    }
    pr *= cnt;
    pr *= (long long)val;
    ans ^= pr;
  }
  printf("%lld\n", ans);
  return 0;
}
