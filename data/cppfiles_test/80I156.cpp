#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, p, i, j, k, m, q, w, h, l, r, x;
  cin >> t;
  while (t--) {
    string s;
    cin >> n >> s;
    l = n / 2;
    l--;
    r = -1;
    for (i = l; i >= 0; i--) {
      if (s[i] == '0') {
        r = i;
        break;
      }
    }
    if (r != -1) {
      cout << r + 1 << " " << n << " " << r + 2 << " " << n << endl;
    } else if (n % 2 != 0) {
      cout << 1 << " " << n << " " << n / 2 + 1 << " " << n << endl;
    } else {
      cout << 1 << " " << n << " " << n / 2 + 1 << " " << n << endl;
    }
  }
}
