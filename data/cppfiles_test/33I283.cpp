#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long otv, n, l = 0, v, m = -1, k, a[100001];
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m = max(a[i], m);
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == m) {
        otv = max(a[i - 1] * a[i], a[i + 1] * a[i]);
      }
    }
    cout << otv << '\n';
  }
  return 0;
}
