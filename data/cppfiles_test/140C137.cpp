#include <bits/stdc++.h>
using namespace std;
void solve_problem() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i * i <= n; ++i) {
    s.insert(i * i);
  }
  for (int i = 1; i * i * i <= n; ++i) {
    s.insert(i * i * i);
  }
  cout << s.size() << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.exceptions(cin.failbit);
  cin.tie(0);
  int T = 1;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    solve_problem();
  }
}
