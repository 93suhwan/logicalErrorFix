#include <bits/stdc++.h>
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001;
void solve() {
  int x, y;
  cin >> x >> y;
  if (x > y)
    cout << x + y << nl;
  else if (x == y)
    cout << x << nl;
  else {
    cout << y - (y % x) / 2 << nl;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
