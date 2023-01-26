#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
void solve() {
  long long s, n;
  cin >> n >> s;
  if (n > s)
    cout << 0 << endl;
  else
    cout << s / (n - (n - 1) / 2) << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int _t = 1;
  cin >> _t;
  for (int _ = 0; _ < (_t); ++_) {
    solve();
  }
  return 0;
}
