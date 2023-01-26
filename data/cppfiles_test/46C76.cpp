#include <bits/stdc++.h>
using namespace std;
void GO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  int t, n, s, m;
  cin >> t;
  while (t--) {
    cin >> n;
    s = 0;
    int a[n];
    cin >> m;
    a[0] = m;
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      if (a[i] > m) {
        m = a[i];
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] > a[n - 1]) {
        s++;
        a[n - 1] = a[i];
      }
      if (a[n - 1] == m) {
        break;
      }
    }
    cout << s << endl;
  }
  return 0;
}
