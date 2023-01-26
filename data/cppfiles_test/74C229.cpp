#include <bits/stdc++.h>
using namespace std;
unsigned long long binpow(unsigned long long a, unsigned long long n,
                          unsigned long long p) {
  unsigned long long res = 1;
  while (n)
    if (n & 1) {
      res = res * a % p;
      --n;
    } else {
      a = a * a % p;
      n >>= 1;
    }
  return res % p;
}
unsigned long long obr(unsigned long long a, unsigned long long p) {
  return binpow(a, p - 2, p);
}
char next_char(char c) {
  if (c == 'R')
    return 'B';
  else
    return 'R';
}
char that_char(char c) {
  if (c == 'R')
    return 'R';
  else
    return 'B';
}
int main() {
  int t, n, i, j, k, a, b;
  vector<int> otv;
  cin >> t;
  for (j = 0; j < t; j++) {
    cin >> a >> b;
    n = a + b;
    if (a == 0 || b == 0) {
      if ((n + 1) % 2)
        cout << 1 << "\n" << n / 2 << "\n";
      else
        cout << 2 << "\n" << n / 2 << " " << n / 2 + 1 << "\n";
    } else {
      if (!(n % 2)) {
        a = min(a, b);
        b = n - a;
        int c = n / 2 - a;
        int d = n - c;
        cout << (d - c + 1) / 2 + 1 << "\n";
        for (i = c; i <= d; i += 2) {
          cout << i << " ";
        }
        cout << "\n";
      } else {
        a = min(a, b);
        b = n - a;
        int c = n / 2 - a;
        int d = n - c;
        cout << d - c + 1 << "\n";
        for (i = c; i <= d; i++) cout << i << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
