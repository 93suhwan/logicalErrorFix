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
    int t = a[i].length();
    int l = 0;
    for (int j = 0; j < t; ++j) {
      if (a[i][j] == 'N') ++l;
    }
    if (l != 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
