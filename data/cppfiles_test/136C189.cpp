#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 10;
const int inf = 1e9;
int t;
int n;
int b[N], ans[N];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  long long tot = 0;
  for (int i = 0; i < n; i++) tot += b[i];
  if (tot % (n * (n + 1) / 2) != 0) {
    cout << "NO\n";
    return;
  }
  tot /= n * (n + 1) / 2;
  for (int i = 0; i < n; i++) {
    long long tmp = b[(i - 1 + n) % n] - b[i] + tot;
    if (tmp <= 0 || tmp % n != 0 || tmp / n > inf) {
      cout << "NO\n";
      return;
    }
    ans[i] = tmp / n;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
