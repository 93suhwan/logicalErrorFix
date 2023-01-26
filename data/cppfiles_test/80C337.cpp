#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i + 1 <= n / 2) {
          cout << i + 1 << " " << n << " " << i + 2 << " " << n << '\n';
          break;
        } else {
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << '\n';
          break;
        }
      }
    }
    if (count(s.begin(), s.end(), '0') == 0) {
      cout << 1 << " " << n - 1 << " " << 2 << " " << n << '\n';
    }
  }
  return 0;
}
