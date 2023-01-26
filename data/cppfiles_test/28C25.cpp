#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a[4];
    long long mixn = 100000001, next, ans = 0, sum = 0;
    for (int i = 1; i <= 3; i++) {
      cin >> a[i];
      sum += a[i] * i;
    }
    if (sum & 1)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
}
