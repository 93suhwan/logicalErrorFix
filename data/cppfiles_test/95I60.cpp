#include <bits/stdc++.h>
using namespace std;
const long long mod = 3e18;
string Q;
long long bpow(long long n, long long x) {
  if (x < 0) return 0;
  if (x == 0) return 1;
  if (x == 1) return n;
  if (x % 2) return bpow(n, x - 1) % mod * n % mod;
  return bpow(n * n % mod, x / 2) % mod;
}
long long modinverse(long long b) { return bpow(b, mod - 2); }
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s(n, 'R');
    vector<pair<vector<long long>, long long>> v(n,
                                                 {vector<long long>(m), 0ll});
    for (int i = 0; i < n; ++i) {
      v[i].second = i;
      for (int j = 0; j < m; ++j) {
        cin >> v[i].first[j];
      }
    }
    sort(v.begin(), v.end());
    vector<long long> res(m, -1);
    int ind = 0;
    for (int i = 1; i < n; ++i) {
      res.clear(), res.resize(m, -1);
      for (int j = 1; j < m; ++j) {
        long long minr, minb, maxr, maxb;
        minr = minb = 1e17, maxr = maxb = -1e17;
        for (int k = 0; k < i; ++k) {
          minr = min(minr, v[k].first[j]);
          maxr = max(maxr, v[k].first[j]);
        }
        for (int k = i; k < n; ++k) {
          minb = min(minb, v[k].first[j]);
          maxb = max(maxb, v[k].first[j]);
        }
        if (minr > maxb) {
          if (j == 0) break;
          res[j] = 1;
        } else if (minb > maxr) {
          if (res[j - 1] == 1) break;
          res[j] = 0;
        } else {
          break;
        }
      }
      if (res[m - 1] == 1) {
        ind = i;
        break;
      }
    }
    if (res[m - 1] == 1) {
      cout << "YES\n";
      for (int i = 0; i < ind; ++i) {
        s[v[i].second] = 'B';
      }
      cout << s << " ";
      for (int i = 0; i < m; ++i) {
        if (res[i] == 1) {
          cout << i << "\n";
          break;
        }
      }
    } else
      cout << "NO\n";
  }
  return 0;
}
