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
    long long i = 1, lim = n;
    if (a > b) {
      res[n - 1] = res[n - 2];
      res[n - 2] = n;
      a--;
      lim = n - 2;
      i = 1;
    }
    if (b > a) {
      res[0] = 2;
      res[1] = 1;
      b--;
      i = 2;
    }
    for (; i < lim && a > 0 && b > 0; i += 2) {
      res[i + 1] = res[i];
      res[i] = i + 2;
      a--, b--;
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
