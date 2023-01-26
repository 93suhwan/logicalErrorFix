#include <bits/stdc++.h>
long double eps = 1e-9;
const long long int maxn = 1e17 + 10;
const long long int mod = 998244353;
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = res * a;
    a = a * a;
    b = b / 2;
  }
  return res;
}
long long int po(long long int x, long long int y) {
  long long int res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = ((res % mod) * (x % mod)) % mod;
    y = y >> 1;
    x = ((x % mod) * (x % mod)) % mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long int> ans(n);
    int flag = 1;
    ans[0] = 0;
    for (int i = 1; i < n; i++) {
      long long int num = a[i - 1] - a[i] - a[n - 1] + a[0];
      if (num % n != 0) flag = 0;
      ans[i] = num / n;
    }
    long long int no = 1, num = a[0];
    for (int i = n - 1; i >= 1; i--) {
      long long int fac = n + 1 - i;
      no += fac;
      num -= (fac * ans[i]);
    }
    if (num % no != 0 || num < 0) flag = 0;
    ans[0] = num / no;
    for (int i = 1; i < n; i++) {
      ans[i] += ans[0];
      if (ans[i] <= 0) flag = 0;
    }
    if (ans[0] <= 0) flag = 0;
    if (flag) {
      cout << "YES" << '\n';
      for (int i = 0; i < n; i++) cout << ans[i] << " ";
      cout << '\n';
    } else
      cout << "NO" << '\n';
  }
}
