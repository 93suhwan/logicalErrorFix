#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, x;
  cin >> n;
  for (int i = 2; i < n; ++i) {
    cout << "? ";
    for (int j = 0; j < n - 1; ++j) cout << "1 ";
    cout << n - i << endl;
    cin >> k;
    if (k) {
      k = i + 1;
      break;
    }
  }
  vector<int> ans(n);
  ans[n - 1] = k;
  for (int i = 1; i < n + 1; ++i) {
    cout << "? ";
    for (int j = 0; j < n - 1; ++j) cout << k << ' ';
    cout << i << endl;
    cin >> x;
    if (x) ans[x - 1] = i;
  }
  cout << "! ";
  for (auto x : ans) cout << x << ' ';
  return 0;
}
