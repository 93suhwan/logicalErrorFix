#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int a[n], k = 1;
    a[0] = k;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'E') {
        a[i + 1] = k;
      } else {
        k = k + 1;
        a[i + 1] = k;
      }
    }
    if ((n > 2) && (s[n - 2] == 'N') && (s[n - 1] == 'E')) a[n - 1] = a[0];
    if (s[n - 1] == 'E') {
      if (a[n - 1] == a[0])
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else if ((s[n - 1] == 'N') || (s[0])) {
      if (a[n - 1] != a[0])
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
    cout << "\n";
  }
  return 0;
}
