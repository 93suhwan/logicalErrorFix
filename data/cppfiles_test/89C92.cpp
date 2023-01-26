#include <bits/stdc++.h>
using namespace std;
int t, n, a[100001], flag;
void solve() {
  int flag = 0, b;
  for (int i = 1; i <= n; i++) {
    cin >> b;
    int k = 0;
    while (b % (i + 1 - k) == 0 && k <= i - 1) k++;
    if (k == i) flag = 1;
  }
  if (flag)
    cout << "NO";
  else
    cout << "YES";
}
int main() {
  for (cin >> t; t--; cout << endl) {
    cin >> n;
    solve();
  }
  return 0;
}
