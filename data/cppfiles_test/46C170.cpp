#include <bits/stdc++.h>
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("Ofast")
#pragma optimize("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 2 * (int)1e9;
const short INFS = (short)32767;
const ll INFL = (ll)1e18;
const ll MOD = (ll)1000000007;
const ll MULT = (ll)29;
const double EPS = 1e-7;
const double EPS_check = 1e-8;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  int mx = -INF;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    mx = max(mx, v[i]);
  }
  int last = n - 1;
  int cnt = 0;
  while (v[last] != mx) {
    ++cnt;
    for (int i = last - 1; i >= 0; --i) {
      if (v[i] > v[last]) {
        last = i;
        break;
      }
    }
  }
  cout << cnt << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
