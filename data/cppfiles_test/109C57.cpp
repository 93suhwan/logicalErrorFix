#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
constexpr int MAXN = 2e5 + 12;
constexpr int MOD = 998244353;
constexpr int INF = 1e9 + 1;
constexpr int LOG = 2e1 + 5;
constexpr int SQ = 7e2 + 10;
constexpr int ALP = 60;
int n, q, cnt[3][3], a, b, fact[MAXN], invfact[MAXN];
string s;
int add(int a, int b) {
  int c = a + b;
  if (c >= MOD) {
    c -= MOD;
  }
  if (c < 0) {
    c += MOD;
  }
  return c;
}
int mul(int a, int b) { return 1ll * a * b % MOD; }
int pwr(int a, int b) {
  if (!b) {
    return 1;
  }
  int ret = pwr(a, b >> 1);
  ret = mul(ret, ret);
  if (b & 1) {
    ret = mul(ret, a);
  }
  return ret;
}
int inv(int p) { return pwr(p, MOD - 2); }
int C(int x, int k) {
  int ret = fact[x];
  ret = mul(ret, invfact[k]);
  ret = mul(ret, invfact[x - k]);
  return ret;
}
int coding(char c) {
  if (c == 'W') return 0;
  if (c == 'B') return 1;
  return 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  fact[0] = 1;
  invfact[0] = inv(fact[0]);
  for (int i = 1; i <= 2 * n; i++) {
    fact[i] = mul(fact[i - 1], i);
    invfact[i] = inv(fact[i]);
  }
  for (int i = 1; i <= n; i++) {
    cin >> s;
    int x = coding(s[0]);
    int y = coding(s[1]);
    a += (x == 0) + (y == 0);
    b += (y == 1) + (x == 1);
    cnt[x][y]++;
  }
  q = 2 * n - a - b;
  if (a > n || b > n) {
    cout << 0;
    return 0;
  }
  if (a == n || b == n) {
    cout << 1;
    return 0;
  }
  if (cnt[0][0] || cnt[1][1]) {
    cout << C(2 * n - a - b, n - a);
    return 0;
  } else {
    if (cnt[0][1] && cnt[1][0]) {
      cout << add(C(q, n - a), -pwr(2, cnt[2][2]));
    } else {
      int ans = 0;
      if (cnt[0][1] == 0 && cnt[2][1] == 0 && cnt[0][2] == 0) {
        ans++;
      }
      if (cnt[1][0] == 0 && cnt[2][0] == 0 && cnt[1][2] == 0) {
        ans++;
      }
      for (int i = 1; i <= cnt[2][2]; i++) {
        ans = add(ans, mul(pwr(2, i - 1),
                           C(q - 2 - 2 * (i - 1), n - a - 2 - (i - 1))));
        ans = add(ans, mul(pwr(2, i - 1),
                           C(q - 2 - 2 * (i - 1), n - b - 2 - (i - 1))));
      }
      a += cnt[2][2];
      b += cnt[2][2];
      q -= 2 * cnt[2][2];
      if (a != n && b != n) {
        for (int i = 1; i <= cnt[0][2] + cnt[2][0]; i++) {
          ans = add(ans, mul(pwr(2, cnt[2][2]), C(q - 1 - (i - 1), a - 1)));
        }
      }
      cout << ans;
    }
  }
  return 0;
}
