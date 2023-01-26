#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1) {
    cout << -1;
    return;
  }
  vector<int> v(n);
  for (int i = (0); i < (n); i++) {
    v[i] = i + 1;
  }
  for (int i = 1; i < n - 2; i += 2) {
    if (a > 0 || b > 0) {
      swap(v[i], v[i + 1]);
      a--;
      b--;
    }
  }
  if ((a + b) > 0 || (a + b) < -1) {
    cout << -1;
  } else {
    if (b < 0) {
      swap(v[n - 2], v[n - 1]);
    } else if (a < 0) {
      swap(v[0], v[1]);
    }
    for (int i = (0); i < (n); i++) {
      cout << v[i] << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
