#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, match = 0;
    cin >> n;
    vector<long long int> a(n);
    map<long long int, long long int> m;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] <= n && m[a[i]] == 0) match++, m[a[i]]++;
    }
    sort(a.begin(), a.end());
    vector<long long int> v(n + 1);
    for (int i = 1; i <= n; ++i) v[i] = m[i];
    long long int c = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] <= (i + 1) * 2 && v[i + 1] == 0) {
        c++;
        cout << -1 << '\n';
        break;
      }
    }
    if (c == 0) cout << n - match << '\n';
  }
}
