#include <bits/stdc++.h>
using namespace std;
long long isPrime(long long n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  return 1;
}
long long mod(long long n) {
  if (n >= 0)
    return n;
  else
    return (-1) * n;
}
int main() {
  long long z, t, k, i, n, m, x, j, y, l, r, q;
  cin >> t;
  for (z = 0; z < t; z++) {
    string s;
    cin >> s;
    long long a[26], n;
    n = s.size();
    for (i = 0; i < 26; i++) a[i] = 0;
    y = 0;
    for (i = 0; i < n; i++) {
      x = s[i];
      x = x - 97;
      a[x]++;
    }
    x = 0;
    for (i = 0; i < 26; i++) {
      if (a[i] == 1) {
        x++;
      } else if (a[i] >= 2) {
        y++;
      }
    }
    cout << (y + (x / 2)) << "\n";
  }
  return 0;
}
