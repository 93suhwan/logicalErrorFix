#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    int n = a[i].length();
    if (a[i][0] == a[i][n - 1])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
