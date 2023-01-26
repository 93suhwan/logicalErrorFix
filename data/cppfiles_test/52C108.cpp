#include <bits/stdc++.h>
using namespace std;
long long int power(long long int base, long long int n) {
  long long int res = 1;
  while (n != 0) {
    if (n % 2 == 1) {
      res = (res * base) % (1000000000 + 7);
      n--;
    } else {
      base = (base * base) % (1000000000 + 7);
      n = n / 2;
    }
  }
  return res % (1000000000 + 7);
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    string s;
    while (k != 0) {
      if (k % 2 == 0)
        s += '0';
      else
        s += '1';
      k = k / 2;
    }
    long long int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') ans += power(n, i);
      ans %= (1000000000 + 7);
    }
    cout << ans << endl;
  }
}
