#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Print(T v) {
  for (auto i : v) cout << i << (" ");
  cout << '\n';
}
int INF = 1000000007;
long long LINF = 1000000000000000000;
long long mod1 = 998244353;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > vec(n + 1), dop(n + 1), res(n + 1);
  long long riz = 0, fir = 0, sec = 0, sum;
  for (int i = 1; i <= n; i++) {
    cin >> vec[i].first >> vec[i].second;
    riz += vec[i].first - vec[i].second;
    dop[i].first = -(min(m, vec[i].first) - (m - min(m, vec[i].first)));
    dop[i].second = min(m, vec[i].second) - (m - min(m, vec[i].second));
    fir += dop[i].first;
    sec += dop[i].second;
  }
  if (riz + fir > 0) {
    sum = riz + fir;
    for (int i = 1; i <= n; i++) {
      res[i].first = min(m, vec[i].first);
      res[i].second = m - res[i].first;
    }
  } else if (riz + sec < 0) {
    sum = -(riz + sec);
    for (int i = 1; i <= n; i++) {
      res[i].second = min(m, vec[i].second);
      res[i].first = m - res[i].second;
    }
  } else {
    vector<long long> dif(n + 1);
    for (int i = 1; i <= n; i++) dif[i] = dop[i].first;
    long long st = riz + fir;
    for (int i = 1; i <= n; i++) {
      if (st + (dop[i].second - dop[i].first) <= 0) {
        dif[i] += dop[i].second - dop[i].first;
        st += dop[i].second - dop[i].first;
      } else {
        dif[i] += abs(st) + abs(st) % 2;
        st = abs(st) % 2;
      }
      if (st >= 0) break;
    }
    sum = st;
    for (int i = 1; i <= n; i++) {
      res[i].first = (m - dif[i]) / 2;
      res[i].second = m - res[i].first;
    }
  }
  cout << (sum) << '\n';
  for (int i = 1; i <= n; i++)
    cout << res[i].first << " " << res[i].second << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
