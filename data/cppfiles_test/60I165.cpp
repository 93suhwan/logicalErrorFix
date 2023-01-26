#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, it;
  cin >> t;
  for (it = 1; it <= t; it++) {
    long long int n, i, j, d, a, b, x, minimum = 100000000000;
    cin >> n;
    long long int ara[1000];
    for (i = 0; i < n; i++) {
      cin >> ara[i];
    }
    if (n == 1) {
      cout << ara[0] << endl;
    } else {
      for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
          d = ara[i] & ara[j];
          if (d < minimum) {
            a = i;
            b = j;
            minimum = d;
          }
        }
      }
      x = minimum;
      cout << x << endl;
    }
  }
  return 0;
}
