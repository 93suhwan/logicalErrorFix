#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    if (m > n) {
      cout << "NO" << endl;
      continue;
    }
    if (m == n) {
      if (a == b)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      continue;
    }
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 && j >= 0) {
      if (a[i] == b[j]) {
        j--;
        i--;
      } else {
        while (i >= 0 && a[i] != b[j]) i -= 2;
      }
    }
    if (j == (-1)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
