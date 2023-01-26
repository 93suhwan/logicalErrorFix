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
    vector<long long int> a(n), v(n + 1);
    map<long long int, long long int> m;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] <= n && v[a[i]] == 0) match++, v[a[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
      if (binary_search(a.begin(), a.end(), i)) {
        m[upper_bound(a.begin(), a.end(), i) - a.begin() - 1] = 1;
      }
    }
    sort(a.begin(), a.end());
    long long int ptr = n, i = n - 1, c = 0;
    while (ptr && i >= 0) {
      while (m[i]) i--;
      if (i < 0) break;
      if (v[ptr] == 0) {
        if (a[i] <= 2 * ptr) {
          cout << -1 << '\n';
          c++;
          break;
        } else
          v[ptr] = 1, ptr--, i--;
      } else {
        ptr--;
        i--;
      }
    }
    if (c == 0) {
      cout << n - match << '\n';
    }
  }
}
