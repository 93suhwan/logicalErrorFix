#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int max(long long int a, long long int b) {
  if (a >= b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a <= b) return a;
  return b;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
bool compare(vector<long long int> a, vector<long long int> b) {
  if (a[0] == b[0]) return a[1] > b[1];
  return a[0] == b[0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<vector<long long int> > arr(n);
    set<vector<long long int> > s;
    for (long long int i = 0; i < n; i++) {
      long long int u, v;
      cin >> u >> v;
      arr[i] = {u, v};
      s.insert({u, v});
    }
    for (long long int i = 0; i < n; i++) {
      long long int l = arr[i][0];
      long long int r = arr[i][1];
      if (l == r) {
        cout << l << " " << r << " " << l << "\n";
        continue;
      }
      if (s.find({l + 1, r}) != s.end()) {
        cout << l << " " << r << " " << l << "\n";
        continue;
      } else if (s.find({l, r - 1}) != s.end()) {
        cout << l << " " << r << " " << r << "\n";
        continue;
      }
      for (long long int d = l + 1; d < r; d++) {
        bool a = false;
        bool b = false;
        if (d - 1 == l)
          a = true;
        else {
          a = (s.find({l, d - 1}) != s.end());
        }
        if (d + 1 == r)
          b = true;
        else {
          b = (s.find({d + 1, r}) != s.end());
        }
        if (a && b) {
          cout << l << " " << r << " " << d << "\n";
          break;
        }
      }
    }
    cout << "\n";
  }
}
