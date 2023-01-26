#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = i - 1;
    vector<int> used(n, 0);
    bool f = 1;
    while (f) {
      f = 0;
      int q = n - 1;
      while (q >= 0) {
        if (a[q] % (q + 2) && !used[q]) {
          f = 1;
          used[q] = 1;
          break;
        }
        if (b[q] >= 0 && used[b[q]]) b[q] = b[b[q]];
        q = b[q];
      }
    }
    f = 1;
    for (int i = 0; i < n; i++)
      if (!used[i]) f = 0;
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
