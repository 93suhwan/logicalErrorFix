#include <bits/stdc++.h>
using namespace std;
int a[9999];
int main() {
  int t;
  cin >> t;
  while (t--) {
    char c;
    bool b = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> c;
      a[i] = c - '0';
    }
    for (int i = 1; i <= n; i++) {
      cin >> c;
      a[i] += c - '0';
      if (a[i] == 2) {
        b = 1;
      }
    }
    if (b)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
