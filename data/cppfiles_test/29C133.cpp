#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long col[2], a, one = 1;
    col[0] = 0;
    col[1] = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (a < 2) col[a]++;
    }
    if (col[1] == 0)
      cout << 0 << "\n";
    else {
      long long ans = (one << col[0]);
      ans = ans * col[1];
      cout << ans << "\n";
    }
  }
}
