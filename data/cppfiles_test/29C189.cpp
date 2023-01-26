#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2 == 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long a1 = 0, a0 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) a1++;
      if (a[i] == 0) a0++;
    }
    cout << (a1 * power(2, a0));
    cout << endl;
  }
  return 0;
}
