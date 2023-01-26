#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::swap;
using std::vector;
using ll = long long;
ll solve(const vector<pair<int, int> > &v) {
  int n = v.size();
  std::map<int, int> mp;
  for (auto [ix, iy] : v) mp[ix]++;
  ll pc = 0;
  for (auto [ix, iy] : v) pc += n - mp[ix];
  pc >>= 1;
  ll res = 0;
  for (auto [ix, iy] : v) res += pc - mp[ix] * ll(n - mp[ix]);
  return res / 3;
}
ll solve2(const vector<pair<int, int> > &v) {
  int n = v.size();
  std::map<int, ll> sx, sy, sx2, sy2;
  for (auto [ix, iy] : v) {
    sx[ix]++;
    sy[iy]++;
  }
  ll pc = 0;
  for (auto [ix, iy] : v) {
    ll d = n - sx[ix] - sy[iy] + 1;
    sx2[ix] += d;
    sy2[iy] += d;
    pc += d;
  }
  pc >>= 1;
  ll res = 0;
  for (auto [ix, iy] : v) {
    ll r = sx2[ix] + sy2[iy] - (n - sx[ix] - sy[iy] + 1) -
           ll(sx[ix] - 1) * (sy[iy] - 1);
    res += pc - r;
  }
  return res / 3;
}
void testc() {
  int n;
  std::cin >> n;
  vector<pair<int, int> > v(n);
  ll ans = 0;
  for (auto &i : v) std::cin >> i.first >> i.second;
  ans += solve(v);
  for (auto &i : v) swap(i.first, i.second);
  ans += solve(v);
  for (auto &i : v) swap(i.first, i.second);
  ans -= solve2(v);
  cout << ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    testc();
    if (t) putchar('\n');
  }
  return 0;
}
