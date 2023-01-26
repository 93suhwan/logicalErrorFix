#include <bits/stdc++.h>
long long q_pow(long long x, long long n, long long mod) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = x * ret % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
long long getbit(long long now) {
  int cnt = 0;
  while (now) {
    cnt++;
    now -= (now) & (-now);
  }
  return cnt;
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
using namespace std;
const long long maxn = 1e5 + 10;
const long long INF = 0x3f3f3f3f;
const long long IINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const long long mod = 998244353;
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
void mul(long long &x, long long y) {
  x -= y;
  if (x < 0) x += mod;
}
char s1[maxn];
char s2[maxn];
void solve() {
  int n;
  cin >> n;
  cin >> (s1 + 1);
  cin >> (s2 + 1);
  int ans = 0;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    s1[i] -= '0';
    s2[i] -= '0';
  }
  for (int i = 1; i <= n; i++) {
    if (s1[i] == 0 or s2[i] == 0) {
      if (cnt0) ans++;
      cnt0 = 1;
    }
    if (s1[i] == 1 or s2[i] == 1) {
      cnt1 = 1;
    }
    if (cnt1 and cnt0) ans += 2, cnt1 = cnt0 = 0;
  }
  if (cnt0) ans++;
  cout << ans << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
