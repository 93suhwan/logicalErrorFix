#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}
long long moduloexp(long long x, long long y, long long m) {
  if (y == 0) {
    return 1;
  }
  if (y % 2 == 0) {
    return (moduloexp(x, y / 2, m) * (moduloexp(x, y / 2, m))) % m;
  } else {
    return ((x % m) * (moduloexp(x, y - 1, m))) % m;
  }
}
long long modulofacto(long long n, long long p) {
  if (n >= p) {
    return 0;
  } else {
    long long result = 1;
    for (long long i = 1; i <= n; i++) {
      result = (result * i) % p;
    }
    return result;
  }
}
long long fx(string s) {
  string s1 = s;
  string s2 = s;
  sort((s1).begin(), (s1).end());
  sort((s2).begin(), (s2).end());
  reverse((s2).begin(), (s2).end());
  long long x1 = stol(s1);
  long long x2 = stol(s2);
  return x2 - x1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    long long a[7];
    for (long long i = 0; i < 7; i++) {
      cin >> a[i];
    }
    cout << a[0] << " " << a[1] << " " << a[6] - a[1] - a[0] << endl;
  }
}
