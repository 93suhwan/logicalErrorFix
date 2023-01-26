#include <bits/stdc++.h>
using namespace std;
const bool ready = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  return true;
}();
using ld = long double;
const ld PI = acos((ld)-1);
using ll = long long;
using pii = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vd = vector<ld>;
using vb = vector<bool>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
void solve() {
  ll n;
  cin >> n;
  ;
  ll m;
  cin >> m;
  ;
  vs s(n);
  for (ll i = 0; i < ll(n); i++) {
    cin >> s[i];
  };
  vi id(n);
  iota((id).begin(), (id).end(), 0LL);
  for (ll i = 0; i < n; i++) {
    for (ll j = 1; j < m; j += 2) {
      s[i][j] = 'Z' - s[i][j];
    }
  }
  sort((id).begin(), (id).end(), [&](ll i1, ll i2) { return s[i1] < s[i2]; });
  for (ll i = 0; i < n; i++) cout << id[i] + 1 << " ";
  cout << "\n";
}
signed main() { solve(); }
