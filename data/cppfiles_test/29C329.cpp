#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int power(long long int b, long long int n) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res *= b;
      n--;
    }
    b *= b;
    n /= 2;
  }
  return res;
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
    s = one * power(2, zero);
    cout << s << '\n';
  }
  return 0;
}
