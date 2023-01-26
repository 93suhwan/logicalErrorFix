#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 200005;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (!a[i] || m[a[i]] == 1) ok = 1;
      m[a[i]] = 1;
    }
    if (ok) {
      cout << "YES\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (m[a[i] - a[j]] || m[a[j] - a[i]]) {
          ok = 1;
          break;
        }
      }
    }
    if (ok) {
      cout << "YES\n";
      continue;
    }
    m.clear();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (m[a[i] - a[j] - a[k]] || m[a[j] - a[i] - a[k]] ||
              m[a[k] - a[j] - a[i]]) {
            ok = 1;
          }
          m[a[i] - a[j] - a[k]] = 1;
          m[a[j] - a[i] - a[k]] = 1;
          m[a[k] - a[j] - a[i]] = 1;
        }
      }
    }
    if (ok) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
