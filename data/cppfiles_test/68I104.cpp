#include <bits/stdc++.h>
using namespace std;
long long nps(long long N) {
  long long nextN = floor(sqrt(N)) + 1;
  return nextN * nextN;
}
bool check(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    long long x;
    cin >> x;
    long long a, b;
    long long y = nps(x);
    if (check(x)) {
      y = sqrt(x);
      cout << y << " " << 1 << "\n";
      continue;
    }
    long long d = y - (sqrt(y) - 1);
    long long g = sqrt(y);
    if (x > d) {
      a = g;
      b = g - (x - d);
    } else if (x < d) {
      b = g;
      a = g - (d - x);
    }
    cout << a << " " << b << "\n";
  }
  return 0;
}
