#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vpii = vector<pii>;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};
const int MOD = 1e9 + 7;
const ll INF = 1e18;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
void solve() {
  string s;
  cin >> s;
  int t1 = 0, t2 = 0, c1 = 5, c2 = 5, i = 0;
  for (; i < (int)s.size(); i++) {
    if (i % 2 == 0) {
      if (s[i] == '1')
        t1++;
      else if (s[i] == '?') {
        if (t1 >= t2) ++t1;
      }
      --c1;
    } else {
      if (s[i] == '1')
        t2++;
      else if (s[i] == '?') {
        if (t2 >= t1) ++t2;
      }
      --c2;
    }
    if ((t1 - t2 > c2) || (t2 - t1 > c1)) break;
  }
  cout << min(10, max(i + 1, 6)) << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
