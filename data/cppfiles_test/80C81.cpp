#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idx = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        idx = i;
        break;
      }
    }
    if (idx != -1) {
      if (idx < n / 2) {
        cout << idx + 1 << ' ' << n << ' ' << idx + 2 << ' ' << n << '\n';
      } else {
        cout << 1 << ' ' << idx + 1 << ' ' << 1 << ' ' << idx << '\n';
      }
    } else {
      cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
    }
  }
  return 0;
}
