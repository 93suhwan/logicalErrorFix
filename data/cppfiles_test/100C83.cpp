#include <bits/stdc++.h>
using namespace std;
int main() {
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
    int r = a[0], h = a[0];
    for (int i = 1; i < n; i++) {
      h = max(h, a[i] - r);
      r += a[i] - r;
    }
    cout << h << endl;
  }
}
