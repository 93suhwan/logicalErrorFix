#include <bits/stdc++.h>
using namespace std;
using Vi = vector<int>;
using i64 = long long;
using ll = long long;
using Pi = pair<int, int>;
mt19937 mrand(time(0));
int rnd(int x) { return mrand() % x; }
const int N = 500005;
const int M = 40005;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    ll k;
    cin >> n >> k;
    ++k;
    Vi a(n);
    vector<ll> ten(15);
    ten[0] = 1;
    for (int i = 1; i < 15; ++i) ten[i] = ten[i - 1] * 10;
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      ll t = (i == n - 1 ? 1000000001 : ten[a[i + 1] - a[i]] - 1);
      ll tmd = min(t, k);
      ans += tmd * ten[a[i]];
      k -= tmd;
    }
    cout << ans << endl;
  }
  return 0;
}
