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
vector<vector<long long>> segmx, segmn;
long long sz;
void fixmx(long long i, long long j) {
  segmx[i][j] = max(segmx[i][j * 2 + 1], segmx[i][j * 2]);
  if (j != 1) fixmx(i, j / 2);
}
void fixmn(long long i, long long j) {
  segmn[i][j] = min(segmn[i][j * 2 + 1], segmn[i][j * 2]);
  if (j != 0) fixmn(i, j / 2);
}
void addmx(long long i, long long j, long long x) {
  segmx[i][j] = x;
  fixmx(i, j / 2);
}
void addmn(long long i, long long j, long long x) {
  segmn[i][j] = x;
  fixmn(i, j / 2);
}
long long getmx(long long i, long long lor, long long ror, long long l = 0,
                long long r = sz, long long x = 1) {
  if (l >= ror || r <= lor) return -1e17;
  if (l >= lor && r <= ror) return segmx[i][x];
  long long mid = (l + r) / 2;
  return max(getmx(i, lor, ror, l, mid, x * 2),
             getmx(i, lor, ror, mid, r, x * 2 + 1));
}
long long getmn(long long i, long long lor, long long ror, long long l = 0,
                long long r = sz, long long x = 1) {
  if (l >= ror || r <= lor) return 1e17;
  if (l >= lor && r <= ror) return segmn[i][x];
  long long mid = (l + r) / 2;
  return min(getmn(i, lor, ror, l, mid, x * 2),
             getmn(i, lor, ror, mid, r, x * 2 + 1));
}
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
    sz = 1ll << int(ceil(log2(n)) + 0.8);
    segmn.clear(), segmn.resize(m, vector<long long>(2 * sz, 1e17));
    segmx.clear(), segmx.resize(m, vector<long long>(2 * sz, -1e17));
    for (int i = 0; i < m; ++i) {
      for (int j = sz; j < sz + n; ++j) {
        addmx(i, j, v[j - sz].first[i]);
        addmn(i, j, v[j - sz].first[i]);
      }
    }
    vector<long long> res(m, -1);
    int ind = 0;
    for (int i = 1; i < n; ++i) {
      res.clear(), res.resize(m, -1);
      long long minr, minb, maxr, maxb;
      minr = minb = 1e17, maxr = maxb = -1e17;
      bool flag = false;
      for (int j = 0; j < m; ++j) {
        minr = min(minr, getmn(j, 0, i));
        maxr = max(maxr, getmx(j, 0, i));
        minb = min(minb, getmn(j, i, n));
        maxb = max(maxb, getmx(j, i, n));
        if (!flag) {
          if (minb > maxr) {
            res[j] = 0;
          } else {
            flag = true;
            j--;
            minr = minb = 1e17, maxr = maxb = -1e17;
          }
        } else {
          if (minr > maxb) {
            res[j] = 1;
          } else
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
