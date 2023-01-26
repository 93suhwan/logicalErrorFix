#include <bits/stdc++.h>
using namespace std;
long long po(long long a, long long b) {
  long long m = 1;
  while (b--) {
    m = m % 1000000007;
    m *= a;
    m = m % 1000000007;
  }
  return m;
}
bool pri(int a) {
  if (a == 1) return 0;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return 1;
}
long long a[200000], b, c;
int main() {
  long long t, n, o;
  cin >> t;
  string s;
  while (t--) {
    cin >> n >> s;
    o = 0;
    for (int i = 0; i < n; ++i) {
      if (i != n - 1 && s[i] != '0')
        o += 1 + (s[i] - '0');
      else
        o += (s[i] - '0');
    }
    cout << o << endl;
  }
  return 0;
}
