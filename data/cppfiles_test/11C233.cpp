#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const double eps = 1e-6;
const int N = 1e6 + 7;
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
int T;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    ll ans = 0;
    for (int ch = 0; ch < 5; ch++) {
      vector<int> cnt(n);
      for (int i = 0; i < n; i++) {
        for (auto x : s[i]) {
          if (x == 'a' + ch)
            cnt[i]++;
          else
            cnt[i]--;
        }
      }
      sort(cnt.begin(), cnt.end(), greater<int>());
      ll sum = 0;
      ll tmp = 0;
      for (int i = 0; i < n; i++) {
        if (sum + cnt[i] > 0) {
          sum += cnt[i];
          ++tmp;
        }
      }
      ckmax(ans, tmp);
    }
    cout << ans << "\n";
  }
  return 0;
}
