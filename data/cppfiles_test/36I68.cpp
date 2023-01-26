#include <bits/stdc++.h>
using namespace std;
int t, n, a[111], sum, ind;
bool pr;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    pr = 1;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    for (int i = 2; i * i <= sum; i++)
      if (!(sum % i)) {
        pr = 0;
        break;
      }
    if (!pr) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] & 1) {
        ind = i;
        break;
      }
    }
    cout << n - 1 << endl;
    for (int i = 0; i < n; i++)
      if (i != ind) cout << i + 1 << " ";
    cout << endl;
  }
  return 0;
}
