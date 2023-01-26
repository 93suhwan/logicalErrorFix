#include <bits/stdc++.h>
using lli = long long int;
using li = long int;
using namespace std;
const lli MOD{998244353};
const lli INF{(false ? (INT_MAX - 1) / 2 : (lli)1e18 + 5)};
const lli N{200005};
int main() {
  cout << setprecision(15);
  cin.tie(nullptr)->sync_with_stdio(false);
  li T{1};
  cin >> T;
  while (T--) {
    lli n{};
    cin >> n;
    vector<lli> arr(n);
    for (auto &i : arr) cin >> i;
    vector<lli> ans(n + 1);
    map<lli, lli> cnt;
    for (auto &i : arr) cnt[i]++;
    ans[0] = cnt[0];
    if (ans[0] == 0) {
      cout << 0 << ' ';
      for (lli i{1}; i <= n; ++i) cout << -1 << ' ';
      cout << '\n';
      continue;
    }
    multiset<pair<lli, lli>> mcnt;
    if (cnt[0] > 1) mcnt.insert(make_pair(0, cnt[0]));
    lli add{};
    for (lli i{1}, last{}; i <= n; ++i) {
      ans[i] = cnt[i] + add;
      if (cnt[i] == 0) {
        if (mcnt.empty()) {
          if (i + 1 <= n) ans[i + 1] = -1;
          break;
        }
        auto it{mcnt.end()};
        it--;
        lli a{(*it).first}, b{(*it).second};
        mcnt.erase(it);
        add += i - a;
        if (b > 2) mcnt.insert(make_pair(a, b - 1));
      }
      if (cnt[i] > 1) mcnt.insert(make_pair(i, cnt[i]));
    }
    for (lli i{1}; i <= n; ++i)
      if (ans[i - 1] == -1) ans[i] = -1;
    for (auto &i : ans) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
