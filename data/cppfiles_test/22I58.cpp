#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,mmx,popcnt,fma")
using namespace std;
using ll = long long;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<array<int, 2>> a(n);
  for (auto &[x, y] : a) cin >> x >> y;
  const int R = (int)sqrt(n);
  vector<vector<int>> sp_events(R + 1);
  for (int p = 1; p <= R; ++p) sp_events[p].resize(p);
  vector<int> add_time(n, -1);
  vector<int> events(q);
  int added = 0;
  int ans = 0;
  for (int qq = 0; qq < q; ++qq) {
    int t, i;
    cin >> t >> i;
    --i;
    if (t == 1) {
      ++added;
      assert(add_time[i] == -1);
      auto [x, y] = a[i];
      int p = x + y;
      if (p > R) {
        for (int time = qq; time < q; time += p) {
          ++events[time];
          if (time + x < q) --events[time + x];
        }
      } else {
        ++sp_events[p][qq % p];
        --sp_events[p][(qq + x) % p];
      }
      add_time[i] = qq;
    } else if (t == 2) {
      --added;
      assert(add_time[i] != -1);
      auto [x, y] = a[i];
      int p = x + y;
      if (p > R) {
        for (int time = add_time[i]; time < q; time += p) {
          --events[time];
          if (time + x < q) ++events[time + x];
        }
      } else {
        --sp_events[p][add_time[i] % p];
        ++sp_events[p][(add_time[i] + x) % p];
      }
      int was_active = (qq - add_time[i]) % p <= x;
      ans -= was_active;
      add_time[i] = -1;
    } else
      assert(0);
    ans += events[qq];
    for (int p = 1; p <= R; ++p) ans += sp_events[p][t % p];
    cout << added - ans << '\n';
  }
}
