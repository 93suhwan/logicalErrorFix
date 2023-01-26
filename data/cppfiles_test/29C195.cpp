#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unsigned long long col[2], a;
    col[0] = 0;
    col[1] = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (a < 2) col[a]++;
    }
    if (col[1] == 0)
      cout << 0 << "\n";
    else {
      unsigned long long ans = 1;
      ans = (ans << col[0]);
      ans = ans * col[1];
      cout << ans << "\n";
    }
  }
}
