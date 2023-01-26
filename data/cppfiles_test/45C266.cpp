#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, h = 1, i;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < n; i++) {
      if (a[i] == 1) {
        h++;
        if (i != 0 && a[i - 1] == 1) {
          h += 4;
        }
      } else {
        if (i != 0 && a[i - 1] == 0) {
          h = -1;
          break;
        }
      }
    }
    cout << h << "\n";
  }
}
