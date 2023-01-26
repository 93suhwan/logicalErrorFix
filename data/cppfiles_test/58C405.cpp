#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
long long int binpow(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tc = 1;
  cin >> tc;
  while (tc--) {
    long long int n;
    cin >> n;
    string a;
    string b;
    cin >> a >> b;
    bool f = 0;
    for (long long int i = 0; i < n; i++)
      if (a[i] == '1' && a[i] == b[i]) f = 1;
    if (f)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
  return 0;
}
