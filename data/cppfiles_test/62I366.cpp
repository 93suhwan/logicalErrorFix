#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n == 1) {
      if (a[1] == 1)
        cout << "2 1\n";
      else
        cout << "1 2\n";
    } else {
      for (int i = 1; i <= n + 1; ++i) {
        cout << i << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
