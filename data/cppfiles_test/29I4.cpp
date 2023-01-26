#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ;
  int t;
  long long int n, i, s;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int ara[n];
    long long int one, zero;
    one = zero = 0LL;
    for (i = 0; i < n; i++) {
      cin >> ara[i];
      if (ara[i] == 1)
        one++;
      else if (!ara[i])
        zero++;
    }
    if (!one) {
      cout << 0 << '\n';
      continue;
    }
    s = 0LL;
    if (one > 1)
      s += one;
    else if (one == 1 && !zero)
      s++;
    if (zero > 1) {
      s += zero + 1;
      s++;
    } else if (zero == 1) {
      s += zero;
      s++;
    }
    cout << s << '\n';
  }
  return 0;
}
