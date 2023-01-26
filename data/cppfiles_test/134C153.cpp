#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long gcdforfirst = a[0], gcdforsecond = a[1];
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0)
        gcdforfirst = gcd(gcdforfirst, a[i]);
      else
        gcdforsecond = gcd(gcdforsecond, a[i]);
    }
    bool first = true;
    bool second = true;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        if (a[i] % gcdforsecond == 0) second = false;
      } else {
        if (a[i] % gcdforfirst == 0) first = false;
      }
    }
    if (!first && !second)
      cout << 0 << '\n';
    else if (first)
      cout << gcdforfirst << '\n';
    else
      cout << gcdforsecond << '\n';
    --t;
  }
  return 0;
}
