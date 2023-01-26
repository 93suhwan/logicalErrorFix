#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  unsigned long long t, i, n, s;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n >> s;
    if (n > s)
      cout << 0 << "\n";
    else {
      if (n == 2)
        cout << s / 2 << "\n";
      else {
        n = n / 2 + 1;
        cout << s / n << "\n";
      }
    }
  }
  return 0;
}
