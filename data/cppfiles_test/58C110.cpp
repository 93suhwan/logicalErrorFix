#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i] && a[i] == '1') ok = 0;
    }
    if (ok)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
