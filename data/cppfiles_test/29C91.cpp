#include <bits/stdc++.h>
long long q_pow(long long x, long long n, long long mod) {
  x %= mod;
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
int dx[] = {1, 0};
int dy[] = {0, 1};
using namespace std;
void dbg_out() { cout << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cout << ' ' << H;
  dbg_out(T...);
}
const long long maxn = 1e6 + 5;
const long long maxm = 250 + 10;
const long long INF = 0x3f3f3f3f;
const long long IINF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 998244353;
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
void mul(long long &x, long long y) {
  x -= y;
  if (x < 0) x += mod;
}
long long a[maxn];
map<long long, long long> g;
map<long long, long long> num;
void solve() {
  int n;
  cin >> n;
  long long cnt0 = 0;
  long long cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) cnt0++;
    if (a[i] == 1) cnt1++;
  }
  cout << cnt1 * (1LL << cnt0) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
