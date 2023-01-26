#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], i, b[n];
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    b[0] = a[0];
    for (i = 1; i < n; i++) b[i] = a[i] - a[i - 1];
    sort(b, b + n);
    cout << b[n - 1] << endl;
  }
}
