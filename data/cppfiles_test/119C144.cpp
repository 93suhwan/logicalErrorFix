#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans = ans + a[i];
    }
    if (ans % n == 0)
      cout << 0 << endl;
    else {
      cout << 1 << endl;
    }
  }
}
