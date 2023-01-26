#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int three2n = 1;
  for (int i = 1; i <= n; i++) three2n *= 3;
  for (int k = 1; k < three2n; k++) {
    int k_cp = k;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int s = k_cp % 3;
      k_cp /= 3;
      if (s == 2) s = -1;
      sum += s * a[i];
    }
    if (sum == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) solve();
  return 0;
}
