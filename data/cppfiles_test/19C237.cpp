#include <bits/stdc++.h>
using namespace std;
int a[15];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int res = 1;
  for (int i = 1; i <= n; i++) res *= 3;
  int flag = 0;
  for (int i = 1; i < res; i++) {
    int t = i;
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      int d = t % 3;
      if (d == 1) sum += a[j];
      if (d == 2) sum -= a[j];
      t /= 3;
    }
    if (sum == 0) {
      flag = 1;
      break;
    }
  }
  cout << (flag == 1 ? "YES" : "NO") << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
