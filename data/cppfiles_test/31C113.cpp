#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int testCases = 1;
  cin >> testCases;
  while (testCases--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n % 2 == 0) {
      for (int i = 0; i < n; i += 2) {
        cout << a[i + 1] << " " << -a[i] << " ";
      }
    } else {
      for (int i = 0; i < n - 3; i += 2) {
        cout << a[i + 1] << " " << -a[i] << " ";
      }
      if (a[n - 3] + a[n - 2] != 0) {
        cout << a[n - 1] << " " << a[n - 1] << " " << -(a[n - 3] + a[n - 2]);
      } else if (a[n - 2] + a[n - 1] != 0) {
        cout << -(a[n - 2] + a[n - 1]) << " " << a[n - 3] << " " << a[n - 3];
      } else {
        cout << a[n - 2] << " " << -(a[n - 1] + a[n - 3]) << " " << a[n - 2];
      }
    }
    cout << endl;
  }
  return 0;
}
