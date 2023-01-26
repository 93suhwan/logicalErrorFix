#include <bits/stdc++.h>
using namespace std;
int _t = 1;
template <typename... T, typename Q>
void outputs(Q x, T&&... args) {
  cout << "Case " << _t++ << ": " << x;
  ((cout << " " << args), ...);
  cout << '\n';
}
template <typename... T, typename Q>
void output(Q x, T&&... args) {
  cout << x;
  ((cout << " " << args), ...);
  cout << '\n';
}
void solve() {
  int v[7];
  for (int i = 0; i < 7; i++) cin >> v[i];
  sort(v, v + 7);
  output(v[0], v[1], v[6] - v[1] - v[0]);
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
