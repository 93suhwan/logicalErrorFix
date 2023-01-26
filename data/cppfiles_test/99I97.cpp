#include <bits/stdc++.h>
using namespace std;
long long int add(long long int x, long long int y) {
  long long int ans = x + y;
  return (ans >= 1000000007 ? ans - 1000000007 : ans);
}
long long int sub(long long int x, long long int y) {
  long long int ans = x - y;
  return (ans < 0 ? ans + 1000000007 : ans);
}
long long int mul(long long int x, long long int y) {
  long long int ans = x * y;
  return (ans >= 1000000007 ? ans % 1000000007 : ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, n;
    cin >> x >> n;
    if ((n) % 4 == 0)
      cout << x << '\n';
    else if (n % 4 == 1)
      if (x & 1)
        cout << x + n << '\n';
      else
        cout << x - n << '\n';
    else if (n % 4 == 2)
      cout << x + 1 << '\n';
    else if (x & 1)
      cout << x - 1 - n << '\n';
    else
      cout << x + 1 + n << '\n';
  }
  return 0;
}
