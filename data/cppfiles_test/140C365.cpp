#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, co = 0, l, i, s = 1, c = 8, s1 = 1, c1 = 2;
    cin >> n;
    for (i = 1; i <= n; i++) {
      if (n < s && n < c) break;
      if (s == c) {
        c1++;
        c = c1 * c1 * c1;
      }
      if (s < c) {
        co++;
        s1++;
        s = s1 * s1;
      } else {
        co++;
        c1++;
        c = c1 * c1 * c1;
      }
    }
    cout << co << endl;
  }
}
