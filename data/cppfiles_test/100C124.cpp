#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int out = a[0];
    if (n == 1) {
      out = a[0];
    }
    if (n == 2) {
      out = max(a[0], a[1] - a[0]);
    }
    for (int i = 0; i < n - 1; i++) {
      out = max(out, a[i + 1] - a[i]);
    }
    cout << out << endl;
  }
  return 0;
}
