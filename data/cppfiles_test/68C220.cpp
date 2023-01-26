#include <bits/stdc++.h>
using namespace std;
long long help(long long k) {
  long long x = 1;
  while (x * x < k) {
    x++;
  }
  return x * x;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long pw = help(k);
    long long d = pw - k;
    long long r = sqrt(pw);
    long long a, b;
    if (d < r) {
      a = r;
      b = d + 1;
    } else {
      b = r;
      a = r - (d - (r - 1));
    }
    cout << a << " " << b;
    cout << endl;
  }
  return 0;
}
