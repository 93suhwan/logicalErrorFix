#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int tt = 1; tt <= tc; tt++) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int b[n];
    if (n % 2) {
      b[0] = a[1] + a[2];
      b[1] = -a[0];
      b[2] = -a[0];
      for (int i = 3; i < n; i += 2) {
        b[i] = a[i + 1];
        b[i + 1] = -a[i];
      }
    } else {
      for (int i = 0; i < n; i += 2) {
        b[i] = a[i + 1];
        b[i + 1] = -a[i];
      }
    }
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << endl;
  }
}
