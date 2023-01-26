#include <bits/stdc++.h>
using namespace std;
long long power(long long x, int y) {
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
  long long LOL = 1e9 + 7;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long n;
    long long k;
    cin >> n >> k;
    string s;
    while (k != 0) {
      s += (k % 2 == 0 ? '0' : '1');
      k /= 2;
    }
    long long sol = 0;
    for (int i = 0; i < 32; i++) {
      if (s[i] == '1') {
        sol = (sol + power(n, i)) % LOL;
      }
    }
    cout << sol << endl;
  }
  return 0;
}
