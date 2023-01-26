#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 1e9 + 30;
constexpr long long INFll = 1e18 + 30;
constexpr long long N = 1010;
constexpr long long MOD = 998244353;
constexpr long long al = 'z' - 'a' + 1;
constexpr long long MAXA = 1e6 + 228;
constexpr long long LOG = 31;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long cnt1 = 0;
  long long cnt0 = 0;
  for (long long i = 0; i < (n); ++i) {
    cin >> a[i];
    if (a[i] == 0) ++cnt0;
    if (a[i] == 1) ++cnt1;
  }
  cout << (1ll << cnt0) * cnt1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
