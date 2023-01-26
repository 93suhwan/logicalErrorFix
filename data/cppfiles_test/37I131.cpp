#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int v[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[b] = 1;
  }
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i] == 0) {
      pos = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != pos) cout << pos << " " << i << "\n";
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
