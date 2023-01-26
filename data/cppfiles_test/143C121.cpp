#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = std::pair<ll, ll>;
using pdd = std::pair<double, double>;
namespace Solver {
const ll N = 2e5 + 5;
ll cnt[N];
void main() {
  ll n;
  cin >> n;
  fill(cnt, cnt + n + 1, 0);
  for (ll i = (0), _i = (n); i < _i; ++i) {
    ll x;
    cin >> x;
    cnt[x]++;
  }
  stack<pii> sta;
  ll res = 0;
  cout << cnt[0] << ' ';
  for (ll i = (1), _i = (n); i <= _i; ++i) {
    if (cnt[i - 1] > 1) {
      sta.push({i - 1, cnt[i - 1] - 1});
    } else if (cnt[i - 1] == 0) {
      if (sta.empty()) {
        for (ll j = (i), _j = (n); j <= _j; ++j) cout << "-1 ";
        cout << "\n";
        return;
      }
      res += i - 1 - sta.top().first;
      if (!--sta.top().second) sta.pop();
    }
    cout << res + cnt[i] << ' ';
  }
  cout << '\n';
}
}  // namespace Solver
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ll T;
  for (std::cin >> T; T--;) Solver::main();
  return 0;
}
