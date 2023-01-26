#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  vector<long long> res;
  for (long long i = 1; i <= n; i++) res.push_back(i);
  if ((abs(a - b)) > 1 || ((a + b) > n - 2)) {
    cout << -1 << endl;
    return;
  } else {
    for (int i = 0; i < n - 1 && a > 0 && b > 0; i++) {
      if (a >= b) {
        res[i + 1] = res[i + 2];
        res[i + 2] = i + 2;
        a--, b--;
      }
      if (a < b) {
        res[i + 1] = i + 1;
        res[i] = i + 2;
        a--, b--;
      }
    }
    if (a > 0) {
      res[n - 1] = res[n - 2];
      res[n - 2] = n;
    } else if (b > 0) {
      res[n - 3] = res[n - 2];
      res[n - 2] = n - 2;
    }
    for (long long i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
