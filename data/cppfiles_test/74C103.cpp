#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int n = a + b, k = abs(a - b) / 2;
    if (n % 2) {
      cout << n - k - k + 1 << endl;
      for (int i = k; i <= n - k; i++) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      cout << (n - k - k + 1) / 2 + 1 << endl;
      for (int i = k; i <= n - k; i += 2) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
