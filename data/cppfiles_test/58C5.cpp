#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    bool pos = true;
    char f[n];
    for (i = 0; i < n; i++) {
      cin >> f[i];
    }
    for (i = 0; i < n; i++) {
      char a;
      cin >> a;
      if (a == '1') {
        if (f[i] == '1') pos = false;
      }
    }
    if (pos)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
