#include <bits/stdc++.h>
using namespace std;
long long LOL = 1e9 + 7;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % LOL;
    b = b / 2;
    a = a * a % LOL;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long n;
    long long k;
    cin >> n >> k;
    char s[100];
    int p = 0;
    while (k != 0) {
      s[p] = (k % 2 == 0 ? '0' : '1');
      k /= 2;
      p++;
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
