#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000005];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int t = n;
  int i = 2;
  if (m < 2 && k >= 1)
    cout << "NO" << endl;
  else {
    while ((i / 2) * t < k && i <= m) {
      i += 2;
    }
    if (i > m)
      cout << "NO" << endl;
    else {
      if (k == 0) i = 0;
      int l = k % n;
      int v = (m - i) * (n / 2);
      if (k + l + v == n * m / 2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
