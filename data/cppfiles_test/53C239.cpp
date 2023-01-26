#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    char c;
    string s;
    cin >> n >> c;
    cin >> s;
    int r = 0, rs = 0;
    int d = 0;
    for (auto v : s) {
      if (v != c) {
        r++;
      }
    }
    if (r + n == n) {
      cout << 0 << "\n";
      continue;
    }
    int p = -20;
    for (int i = 2; i <= n; i++) {
      int temp = 1;
      for (int j = i; j <= n; j += i) {
        if (s[j - 1] != c) {
          temp = 0;
          break;
        }
      }
      if (temp == 1) {
        p = i;
        break;
      }
    }
    if (p != -20) {
      cout << 1 << "\n";
      cout << p << "\n";
    } else {
      if (s[n - 1] == c) {
        cout << 1 << "\n";
        cout << n << "\n";
      } else {
        if (r == 1) {
          cout << 1 << "\n";
          cout << n - 1 << "\n";
        } else {
          cout << 2 << "\n";
          cout << n << " " << n - 1 << "\n";
        }
      }
    }
  }
  return 0;
}
