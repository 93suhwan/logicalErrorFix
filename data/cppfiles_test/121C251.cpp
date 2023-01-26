#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 7;
long long int mod(long long int a, long long int m) { return a % m; }
long long int ceel(long long int a, long long int b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long int expo_pow(long long int x, long long int n,
                       long long int m = 1e9 + 7) {
  long long int ans = 1;
  while (n > 0) {
    if (1 & n) {
      ans = mod((mod(ans, m) * mod(x, m)), m);
    }
    x = mod((mod(x, m) * mod(x, m)), m);
    n >>= 1;
  }
  return ans;
}
void testcase(long long int task) {
  string s, t;
  long long int n, m = 0;
  cin >> n >> s >> t;
  long long int l = 0, r = 0, cnt = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] != t[i]) m++;
    if (s[i] == '1' && s[i] != t[i]) l++;
    if (s[i] == '1' && s[i] == t[i]) r++;
    if (t[i] == '1') cnt++;
  }
  if (m % 2 == 0 && (n - m) % 2 != 0 && ceel(m, 2) == l &&
      ceel(n - m, 2) == r) {
    cout << min(m, n - m);
  } else if (m % 2 == 0 && ceel(m, 2) == l) {
    cout << m;
  } else if ((n - m) % 2 != 0 && ceel(n - m, 2) == r) {
    cout << n - m;
  } else {
    cout << "-1";
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long int i = 1; i < t + 1; i++) {
    testcase(t);
  }
  return 0;
}
