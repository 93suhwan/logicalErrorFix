#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const double eps = 1e-6;
const int N = 2e5 + 7;
const ll INF = 0x3f3f3f3f;
const int mod = 1000000007;
const int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, -1, -1, -1, 1, 1, -1, 1, 1};
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
int T, n;
struct Node {
  string s;
  int cnt[5];
} a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i].s;
      for (int j = 0; j < 5; j++) {
        a[i].cnt[j] = 0;
      }
      for (int j = 0; j < a[i].s.length(); j++) {
        a[i].cnt[a[i].s[j] - 'a']++;
      }
    }
    int ans = 0;
    for (int ch = 0; ch < 5; ch++) {
      sort(a, a + n, [ch](const Node& x, const Node& y) {
        return (1.0 * x.cnt[ch] / x.s.length() -
                1.0 * y.cnt[ch] / y.s.length()) < eps
                   ? 1.0 * x.cnt[ch] / x.s.length() >
                         1.0 * y.cnt[ch] / y.s.length()
                   : x.s.length() < y.s.length();
      });
      int sum = 0, other_sum = 0;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (sum + a[i].cnt[ch] > other_sum + a[i].s.length() - a[i].cnt[ch]) {
          ++cnt;
          sum += a[i].cnt[ch];
          other_sum += a[i].s.length() - a[i].cnt[ch];
        } else {
          continue;
        }
      }
      ckmax(ans, cnt);
    }
    cout << ans << "\n";
  }
  return 0;
}
