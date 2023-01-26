#include <bits/stdc++.h>
using namespace std;
long long fact(long long n) {
  long long res = 1;
  while (n > 1) {
    if (n == 2) break;
    res *= n;
    n--;
    res = res % 1000000007;
    if (n == 2) break;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long i, j, k, a, b, t, n, x, ans;
  cin >> t;
  while (t--) {
    cin >> n;
    n *= 2;
    ans = fact(n);
    cout << ans << "\n";
  }
}
