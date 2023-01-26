#include <bits/stdc++.h>
using namespace std;
long long int m, n, c = 0, k = 0, a = 0, b = 0, temp, MAX = 0, MIN = 999999999,
                    sum = 0;
long long int i, j;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int x[n];
    a = 0, b = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> x[i];
    }
    c = max_element(x, x + n) - x;
    if (c == 0) {
      b = x[c] * x[c + 1];
    } else {
      a = x[c] * x[c - 1];
      b = x[c] * x[c + 1];
    }
    cout << max(a, b) << endl;
  }
}
