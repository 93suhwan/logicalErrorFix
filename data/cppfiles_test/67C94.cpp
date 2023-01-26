#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  double p;
  cin >> n >> p;
  for (i = 0; i < n; i++) {
    if ((2ll * i * (i - 1) * (i - 2) + 6ll * (n - i) * i * (i - 1) +
         3ll * (n - i) * (n - i - 1) * i) >=
        2 * p * n * (n - 1) * (n - 2) - 0.00000001) {
      cout << i;
      return 0;
    }
  }
}
