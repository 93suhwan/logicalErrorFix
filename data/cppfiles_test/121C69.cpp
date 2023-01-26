#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
long long int _gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return _gcd(b % a, a);
}
long long int qpow(long long int a, long long int n) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % MOD;
      n--;
    } else {
      n = n / 2;
      a = (a * a) % MOD;
    }
  }
  return res;
}
void soln() {
  int n, i, o0, o1, e0, e1, ans1, ans2;
  string a, b;
  cin >> n >> a >> b;
  o0 = o1 = e0 = e1 = 0;
  for (i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      if (a[i] == '0')
        e0++;
      else
        e1++;
    } else {
      if (a[i] == '0')
        o0++;
      else
        o1++;
    }
  }
  ans1 = ans2 = INT_MAX;
  if (o0 == o1) ans1 = o0 + o1;
  if (e1 == e0 + 1) ans2 = e1 + e0;
  if (ans1 == ans2 && ans1 == INT_MAX)
    cout << -1 << "\n";
  else
    cout << min(ans1, ans2) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) soln();
}
