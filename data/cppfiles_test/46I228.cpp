#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    int k = INT_MIN;
    int kk = INT_MIN;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      k = max(k, a[i]);
    }
    for (int i = 0; i < n; i++) {
      if (a[i] > kk && a[i] != k) {
        kk = a[i];
      }
    }
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == k) {
        cout << count << endl;
        break;
      } else if (a[i] == kk) {
        cout << count + 1 << endl;
        break;
      }
      count++;
    }
  }
  return 0;
}
