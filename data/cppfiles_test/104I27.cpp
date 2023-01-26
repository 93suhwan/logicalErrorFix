#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> s(n), t(n);
  ll total_s = 0;
  ll total_t = 0;
  vector<ll> ps, pt;
  ps.push_back(0);
  pt.push_back(0);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    s[i] = max<ll>(0, m - b);
    t[i] = min<ll>(a, m);
    total_s += s[i];
    total_t += t[i];
    ps.push_back(total_s);
    pt.push_back(total_t);
  }
  ll sum = m * n;
  ll target;
  if (total_s * 2 >= sum) {
    target = total_s;
  } else if (total_t * 2 <= sum) {
    target = total_t;
  } else {
    target = sum / 2;
    assert(target >= total_s && target <= total_t);
  }
  printf("%lld\n", abs(sum - 2 * target));
  vector<ll> ret(n);
  for (int i = n - 1; i >= 0; --i) {
    ll x = max<ll>(target - pt[i], s[i]);
    assert(x >= s[i] && x <= t[i]);
    ret[i] = x;
    target -= x;
  }
  assert(target == 0);
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", (int)ret[i], (int)(m - ret[i]));
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  for (cin >> t; t > 0; --t) {
    solve();
  }
  return 0;
}
