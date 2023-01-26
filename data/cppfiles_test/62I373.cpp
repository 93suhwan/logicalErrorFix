#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, tag = -1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i] == 0) tag = i;
    }
    if (tag == n) {
      if (a[1] == 1) {
        cout << n + 1 << " ";
        for (int i = 1; i <= n; ++i) cout << i << " ";
        cout << "\n";
      } else
        cout << "-1\n";
    } else {
      if (tag == -1)
        cout << tag << "\n";
      else {
        for (int i = 1; i <= tag; ++i) cout << i << " ";
        cout << n + 1 << " ";
        for (int i = tag + 1; i <= n; ++i) cout << i << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
