#include <bits/stdc++.h>
using namespace std;
long long n, m;
int _;
void solve() {
  cin >> n >> m;
  int ans = 0;
  m++;
  for (int i = 30; i >= 0 && n < m; i--) {
    if ((n >> i & 1) == (m >> i & 1)) {
      continue;
    }
    if ((m >> i & 1)) {
      ans |= (1 << i);
      n |= (1 << i);
    }
  }
  cout << ans << "\n";
}
int main() {
  cin >> _;
  while (_--) {
    solve();
  }
}
