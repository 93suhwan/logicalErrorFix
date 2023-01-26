#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[n + 7];
    set<int> Set1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      Set1.insert(a[i]);
    }
    if (n == 1) {
      if (a[1] == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      continue;
    }
    set<int> Set;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        Set.insert(a[i] + a[j]);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        if (Set.count(a[i] - a[j]) > 0 || Set.count(a[j] - a[i]) > 0) {
          cout << "YES\n";
          goto m1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (a[i] == a[j] || a[i] == -a[j]) {
          cout << "YES\n";
          goto m1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (Set1.count(a[i] - a[j]) > 0 || Set1.count(a[j] - a[i]) > 0) {
          cout << "YES\n";
          goto m1;
        }
      }
    }
    cout << "NO\n";
  m1:;
  }
}
