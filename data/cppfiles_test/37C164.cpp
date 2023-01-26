#include <bits/stdc++.h>
int XOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int a, b, c;
  vector<int> v(n + 1, 0);
  for (int i = 0; i < m; i += 1) {
    cin >> a >> b >> c;
    v[b]++;
  }
  int k = -1;
  for (int i = 1; i <= n; i++) {
    if (v[i] == 0) {
      k = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != k) cout << i << " " << k << endl;
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
