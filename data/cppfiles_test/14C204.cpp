#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int a[N];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int l[N];
    int r[N];
    int k = 0;
    for (int i = 0; i < n; i++) {
      int mx = 0;
      for (int j = 1; j < n - i; j++)
        if (a[mx] < a[j]) mx = j;
      if (mx != n - i - 1) {
        l[k] = mx + 1;
        r[k] = n - i;
        k++;
        int t = a[mx];
        for (int j = mx; j < n - i - 1; j++) a[j] = a[j + 1];
        a[n - i - 1] = t;
      }
    }
    cout << k << endl;
    for (int i = 0; i < k; i++) cout << l[i] << ' ' << r[i] << ' ' << 1 << endl;
  }
  return 0;
}
