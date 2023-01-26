#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const int N = 2e5 + 5;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mi(long long x) { return power(x, M - 2, M); }
int nCr(int n, int r) {
  int mod = 1000000007;
  int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = min(i, r); j > 0; j--) {
      C[j] = (C[j] + C[j - 1]) % mod;
    }
  }
  return C[r] % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    long long fg = 0;
    map<long long, long long> mp;
    vector<long long> v2;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      if (mp[v[i]] != 0) {
        fg = 1;
      }
      mp[v[i]]++;
      v2.push_back(v[i]);
    }
    if (fg) {
      cout << "YES" << endl;
    } else {
      sort(v2.begin(), v2.end());
      map<long long, long long> m;
      for (long long i = 0; i < n; i++) {
        m[v2[i]] = i;
      }
      vector<long long> vis(n, 0);
      long long cn1 = 0, cn2 = 0;
      for (long long i = 0; i < n; i++) {
        if (m[v[i]] == i) {
          continue;
        }
        if (!vis[i]) {
          vis[i] = 1;
          long long pres = i;
          long long st = m[v[i]];
          long long cn = 1;
          while (st != pres) {
            vis[st] = 1;
            cn++;
            st = m[v[st]];
          }
          if (cn % 2 != 0) {
            cn1++;
          } else {
            cn2++;
          }
        }
      }
      if (cn2 % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
