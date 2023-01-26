#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 100000;
void solve() {
  ll n, m;
  cin >> n >> m;
  if (n > m)
    cout << 0 << endl;
  else {
    int msb1 = 0, msb2 = 0;
    for (int i = 0, nnnn = (31); i < nnnn; ++i) {
      if (m & (1ll << i)) {
        msb1 = i;
      }
    }
    for (int i = 0, nnnn = (31); i < nnnn; ++i) {
      if (n & (1ll << i)) {
        msb2 = i;
      }
    }
    ll ans1 = 0;
    bool add = true;
    for (int i = msb2 + 1, nnnn = (msb1 + 1); i < nnnn; ++i) {
      if ((1 << i) & (m)) {
        ans1 += (1 << i) & (m);
        if (i != msb2 && i != msb1) add = false;
      }
    }
    if (add) {
      ll temp = 0;
      for (int i = msb2; i >= 0; i--) {
        if (!(n & (1 << i))) temp += (1 << i);
      }
      for (int i = 0, nnnn = (msb2 + 1); i < nnnn; ++i) {
        if (temp & (m + 1) & (1 << i)) ans1 += (1 << i);
      }
    }
    cout << ans1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(12) << fixed;
  int t;
  cin >> t;
  while (t--) solve();
}
