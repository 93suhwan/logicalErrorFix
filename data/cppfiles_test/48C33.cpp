#include <bits/stdc++.h>
using namespace std;
long long n, q;
long long a[100000], b[100000], c[100000];
long long nf[100000], nfr[100000];
long long sf[100000][20], sfr[100000][20];
int32_t main() {
  cin >> n >> q;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n; ++i) cin >> b[i];
  for (long long i = 0; i < n; ++i) c[i] = b[i] - a[i];
  for (long long i = 0; i < n; ++i) {
    nf[i] = -2;
    for (long long z = 0; z < 20; ++z) sf[i][z] = -2;
  }
  map<long long, long long> m;
  m[0] = -1;
  long long off = 0;
  for (long long i = 0; i < n; ++i) {
    off += c[i];
    while (m.size() && (--m.end())->first > off) m.erase(--m.end());
    if (m.count(off)) {
      long long j = m[off];
      long long x = 0;
      long long k = i;
      long long res = 0;
      while (k != j) {
        if (nf[k] == -2) {
          x -= c[k];
          res = max(res, x);
          k--;
        } else {
          res = max(res, nfr[k] + x);
          k = nf[k];
        }
      }
      assert(x == 0);
      if (j != -1 && nf[j] != -2) {
        nf[i] = nf[j];
        nfr[i] = max(nfr[j], res);
      } else {
        nf[i] = j;
        nfr[i] = res;
      }
      sf[i][0] = j;
      sfr[i][0] = res;
      for (long long z = 1; z < 20 && sf[i][z - 1] >= 0; ++z) {
        sf[i][z] = sf[sf[i][z - 1]][z - 1];
        sfr[i][z] = max(sfr[i][z - 1], sfr[sf[i][z - 1]][z - 1]);
      }
    }
    m[off] = i;
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    l -= 2;
    r--;
    long long res = 0;
    for (long long z = 19; z >= 0 && r >= 0; --z) {
      if (sf[r][z] < l) continue;
      res = max(res, sfr[r][z]);
      r = sf[r][z];
    }
    if (l != r) {
      cout << "-1\n";
      continue;
    }
    cout << res << "\n";
  }
}
