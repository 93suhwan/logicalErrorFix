#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int tr = 1;
    for (int i = 0; i < n; i++) tr *= 3;
    bool s = false;
    for (int i = 1; i < tr; i++) {
      int tmp = i;
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (tmp % 3 == 1) sum += a[j];
        if (tmp % 3 == 2) sum -= a[j];
        tmp /= 3;
      }
      if (sum == 0) {
        s = true;
        break;
      }
    }
    if (!s)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
