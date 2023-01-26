#include <bits/stdc++.h>
using namespace std;
void test() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[0] >= 0) {
    long long rem = n % k;
    long long sol = 0;
    for (int i = 0; i < n; i++) {
      if ((i + 1) % k == rem) {
        sol = sol + a[i];
        if (i != n - 1) sol = sol + a[i];
      }
    }
    cout << sol << "\n";
  } else if (a[n - 1] <= 0) {
    for (int i = 0; i < n; i++) a[i] = abs(a[i]);
    sort(a, a + n);
    long long rem = n % k;
    long long sol = 0;
    for (int i = 0; i < n; i++) {
      if ((i + 1) % k == rem) {
        sol = sol + a[i];
        if (i != n - 1) sol = sol + a[i];
      }
    }
    cout << sol << "\n";
  } else {
    int index = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] <= 0) index = i;
    }
    int in = n - 1;
    long long res = 0;
    while (in > index) {
      res = res + (a[in] * 2);
      in = in - k;
    }
    in = index;
    long long b[index + 1];
    for (int i = 0; i < index + 1; i++) b[i] = abs(a[i]);
    sort(b, b + index + 1);
    long long rem = (index + 1) % k;
    for (int i = 0; i < index + 1; i++) {
      if ((i + 1) % k == rem) {
        res = res + b[i];
        if (i != index) res = res + b[i];
      }
    }
    long long res2 = 0;
    in = index;
    while (in >= 0) {
      res2 = res2 + (b[in] * 2);
      in = in - k;
    }
    long long sz = n - (index + 1);
    long long c[sz];
    for (int i = index + 1; i < n; i++) c[i - (index + 1)] = a[i];
    rem = sz % k;
    for (int i = 0; i < sz; i++) {
      if ((i + 1) % k == rem) {
        res2 = res2 + c[i];
        if (i != sz - 1) res2 = res2 + c[i];
      }
    }
    cout << min(res, res2) << "\n";
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    test();
  }
}
