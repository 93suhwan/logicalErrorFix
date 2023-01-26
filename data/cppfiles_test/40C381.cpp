#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
const ll INF = 1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m;
    cin >> m;
    ll a;
    vl a0;
    vl a1;
    for (int _ = (0); _ < (m); ++_) {
      cin >> a;
      a0.push_back(a);
    }
    for (int _ = (0); _ < (m); ++_) {
      cin >> a;
      a1.push_back(a);
    }
    partial_sum(begin(a0), end(a0), begin(a0));
    partial_sum(begin(a1), end(a1), begin(a1));
    ll ans = a0[m - 1] - a0[0];
    for (int i = (1); i < (m); ++i)
      ans = min(ans, max(a0[m - 1] - a0[i], a1[i - 1]));
    cout << ans << "\n";
  }
  return 0;
}
