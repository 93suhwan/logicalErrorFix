#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int cnt = 1, i;
    string a;
    cin >> a;
    if (a.length() % 2) {
      cout << "NO\n";
      continue;
    }
    sort(a.begin(), a.end());
    for (i = 0; i < a.length() - 1; i++) {
      if (a[i] == a[i + 1]) {
        cnt++;
      } else {
        if (cnt % 2) {
          cout << "NO\n";
          break;
        }
        cnt = 1;
      }
    }
    if (i == a.length() - 1) {
      cout << "YES\n";
    }
  }
}
