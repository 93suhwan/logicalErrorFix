#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  if (y == 0)
    return 1;
  else {
    long long int result = power(x, y / 2) % 1000000007;
    if (y % 2 == 0)
      return (result % 1000000007 * result % 1000000007) % 1000000007;
    else
      return (result % 1000000007 * result % 1000000007 * x % 1000000007) %
             1000000007;
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() % 2 != 0) {
      cout << "NO" << '\n';
    } else {
      int n = s.length() / 2;
      string s1, s2;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == s[i + n])
          cnt++;
        else
          break;
      }
      if (cnt == n) {
        cout << "YES" << '\n';
      } else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
