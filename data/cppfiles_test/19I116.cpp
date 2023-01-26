#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> adj;
map<long, bool> vis, viss;
vector<long long> parent, sz;
long long components = 0;
long long dr[] = {1, 0, -1, 0};
long long dc[] = {0, 1, 0, -1};
int spf[1000000 + 1];
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(nullptr);
  long long t, temp;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      cin >> temp;
      v.push_back(temp);
    }
    string ans = "NO";
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n - 1; j++) {
        for (long long k = j + 1; k < n; k++) {
          if (i != j && i != k) {
            if (v[i] == v[j] || v[i] == v[k] || v[i] == v[j] + v[k] ||
                v[i] == abs(v[j] - v[k]))
              ans = "YES";
            if (abs(v[j] - v[k]) >= 0 && abs(v[j] - v[k]) < n) ans = "YES";
            if (abs(v[j] + v[k]) >= 0 && abs(v[j] + v[k]) < n) ans = "YES";
          }
        }
      }
    }
    if (n == 1 && v[0] == 0) ans = "YES";
    cout << ans << "\n";
  }
  return 0;
}
