#include <bits/stdc++.h>
using namespace std;
const long long MOD = pow(10, 9) + 7;
long long fac[1001];
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
void SieveOfEratosthenes(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) {
    }
}
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
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long nCrModPFermat(long long n, long long r, long long p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
void dfs(long long v, vector<vector<long long>> &adj,
         vector<long long> &visited) {
  for (long long u : adj[v]) {
    if (!visited[u]) {
      visited[u] = 1;
    }
  }
}
long long parent[300002], sz[300002];
long long find_set(long long v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void make_set(long long v) {
  parent[v] = v;
  sz[v] = 1;
}
void union_sets(long long a, long long b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}
class segTree {
 public:
  long long len;
  vector<long long> a;
  vector<pair<long long, long long>> t;
  segTree(vector<long long> &val) {
    len = val.size();
    a.resize(len);
    long long i;
    a = val;
    if ((len & (len - 1)) != 0) {
      long long np = ceil(log2(len));
      long long pval = pow(2, np);
      long long diff = pval - len;
      len = pval;
      for (i = 0; i < diff; i++) a.push_back(pow(10, 10));
    }
    t.resize(4 * len + 1);
  }
  void build(long long idx, long long tl, long long tr) {
    if (tl == tr) {
      t[idx] = {a[tl], 1};
      return;
    }
    long long tm = (tl + tr) / 2;
    build(idx * 2, tl, tm);
    build(idx * 2 + 1, tm + 1, tr);
    long long count = 0;
    long long mn = min(t[2 * idx].first, t[2 * idx + 1].first);
    if (mn == t[2 * idx].first) count += t[2 * idx].second;
    if (mn == t[2 * idx + 1].first) count += t[2 * idx + 1].second;
    t[idx] = {mn, count};
  }
  pair<long long, long long> query(long long idx, long long tl, long long tr,
                                   long long l, long long r) {
    if (l > r) return {pow(10, 10), 1};
    if (l == tl && r == tr) {
      return t[idx];
    }
    long long tm = (tl + tr) / 2;
    pair<long long, long long> res1 = query(idx * 2, tl, tm, l, min(r, tm));
    pair<long long, long long> res2 =
        query(idx * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    if (res1.first < res2.first) {
      return res1;
    } else if (res2.first < res1.first) {
      return res2;
    } else {
      return {res1.first, res1.second + res2.second};
    }
  }
  void update(long long idx, long long tl, long long tr, long long pos,
              long long val) {
    if (tl == tr) {
      t[idx] = {val, 1};
      return;
    }
    long long tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * idx, tl, tm, pos, val);
    else
      update(2 * idx + 1, tm + 1, tr, pos, val);
    long long count = 0;
    long long mn = min(t[2 * idx].first, t[2 * idx + 1].first);
    if (mn == t[2 * idx].first) count += t[2 * idx].second;
    if (mn == t[2 * idx + 1].first) count += t[2 * idx + 1].second;
    t[idx] = {mn, count};
  }
};
void solve() {
  long long i, j, n, m, k;
  cin >> n >> m >> k;
  if (n % m == 0) {
    for (i = 1; i <= k; i++) {
      for (j = 1; j <= m; j++) {
        long long z = n / m;
        cout << z << " ";
        long long s = z * (j - 1) + 1;
        long long e = z * j;
        for (int r = s; r <= e; r++) {
          cout << r << " ";
        }
        cout << '\n';
      }
    }
    return;
  }
  long long big = n % m, sm = m - big;
  long long c = 1;
  for (i = 1; i <= k; i++) {
    long long z = n / m;
    for (j = 1; j <= big; j++) {
      cout << z + 1 << " ";
      for (long long r = 1; r <= z + 1; r++) {
        cout << c << " ";
        c++;
        if (c > n) c = 1;
      }
      cout << '\n';
    }
    long long s = c;
    for (j = 1; j <= sm; j++) {
      cout << z << " ";
      for (long long r = 1; r <= z; r++) {
        cout << s << " ";
        s++;
        if (s > n) s = 1;
      }
      cout << '\n';
    }
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 2;
  switch (test) {
    case 1:
      solve();
      break;
    case 2: {
      long long t;
      cin >> t;
      while (t--) {
        solve();
      }
    }; break;
  }
}
