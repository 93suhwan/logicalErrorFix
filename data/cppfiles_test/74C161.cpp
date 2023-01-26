#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    int n1 = n / 2, n2 = n - n1;
    vector<int> res(n + 1);
    for (int sw = 0; sw < 2; ++sw) {
      for (int i = max(0, a - n2); i <= min(a, n1); ++i) {
        res[n1 - i + a - i] = 1;
      }
      swap(n1, n2);
    }
    int m = 0;
    for (int i = 0; i <= n; ++i) {
      m += res[i];
    }
    cout << m << endl;
    for (int i = 0; i <= n; ++i) {
      if (res[i]) {
        cout << i << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}
