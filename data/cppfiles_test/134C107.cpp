#include <bits/stdc++.h>
using namespace std;
long long gcd(const long long& tmp, const long long& b) {
  if (!tmp || !b) return 0;
  return tmp % b == 0 ? b : gcd(b, tmp % b);
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    long long g1, g2;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    g1 = a[0];
    g2 = a[1];
    for (int i = 0; i < n; i++) {
      if (i > 1) {
        if (i & 1) {
          g2 = gcd(g2, a[i]);
        } else {
          g1 = gcd(g1, a[i]);
        }
      }
    }
    if (g1 == g2) {
      cout << 0 << "\n";
      continue;
    }
    bool flag = 0;
    for (int i = 0; i < n - 1; i++) {
      if ((a[i] % g1 && (!(a[i + 1] % g1))) ||
          (a[i + 1] % g1 && (!(a[i] % g1))))
        ;
      else {
        flag = 1;
      }
    }
    if (!flag) {
      cout << g1 << "\n";
      continue;
    }
    flag = 0;
    for (int i = 0; i < n - 1; i++) {
      if ((a[i] % g2 && (!(a[i + 1] % g2))) ||
          (a[i + 1] % g2 && (!(a[i] % g2))))
        ;
      else {
        flag = 1;
      }
    }
    if (!flag) {
      cout << g2 << "\n";
      continue;
    } else {
      cout << 0 << "\n";
    }
  }
  return 0;
}
