#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long k;
  while (t--) {
    cin >> k;
    int n = ceil(sqrt(k));
    if (n * n - k >= n) {
      printf("%d %d\n", n - (n * n - k - n) - 1, n);
    } else {
      printf("%d %d\n", n, (n * n - k) + 1);
    }
  }
  return 0;
}
