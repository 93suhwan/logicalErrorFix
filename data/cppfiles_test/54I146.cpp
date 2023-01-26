#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1);
long long mod = 1e9 + 7;
int xc[] = {0, 1, 0, -1, -1, -1, 1, 1};
int yc[] = {1, 0, -1, 0, -1, 1, -1, 1};
long double Q;
vector<bool> isprime(1e5 + 1, true);
vector<vector<long long>> primes(1e5 + 1);
vector<long long> primesind;
void sieve() {
  isprime[0] = isprime[1] = false;
  for (size_t i = 2; i <= 100000; i++) {
    if (isprime[i]) {
      primesind.push_back(i);
      for (size_t j = 2 * i; j <= 100000; j += i) {
        isprime[j] = false;
      }
    }
  }
}
long long bpow(long long n, long long x) {
  if (x < 0) return 0;
  if (x == 0) return 1;
  if (x == 1) return n;
  if (x % 2) return bpow(n, x - 1) % mod * n % mod;
  return bpow(n * n % mod, x / 2) % mod;
}
long long modinverse(long long b) { return bpow(b, mod - 2); }
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
long long fact(long long n, long long en = 1) {
  if (n <= en) return 1;
  return n * fact(n - 1, en) % mod;
}
long long perm(long long n, long long k) { return fact(n, n - k); }
long long comb(long long n, long long k) {
  return fact(n, max(k, n - k)) * modinverse(fact(min(k, n - k))) % mod;
}
vector<long long> seg;
long long segsz;
long long merge(long long x, long long y) { return max(x, y); }
void add(long long i, long long x) {
  i += segsz;
  seg[i] = x;
  while (i) {
    i /= 2;
    seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
  }
  return;
}
long long findseg(long long lo = 0, long long ro = segsz, long long l = 0,
                  long long r = segsz, long long x = 1) {
  if (l >= ro || r <= lo) return 0;
  if (l >= lo && r <= ro) return seg[x];
  long long mid = (l + r) / 2;
  return merge(findseg(lo, ro, l, mid, x * 2),
               findseg(lo, ro, mid, r, x * 2 + 1));
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, ai = 1;
    cin >> n >> m;
    vector<long long> v(n + 1), val(n + 1);
    vector<vector<long long>> gr(1);
    bool flag = false;
    for (size_t i = 0; i < m; i++) {
      long long x, y;
      string s;
      cin >> x >> y >> s;
      bool c = (s == "imposter");
      if (v[x] == 0 && v[y] == 0) {
        v[x] = v[y] = ai;
        gr.push_back({x, y});
        ai++;
        if (c)
          val[x] = 1, val[y] = -1;
        else
          val[x] = val[y] = 1;
      } else if (v[x] == 0) {
        v[x] = v[y];
        gr[v[y]].push_back(x);
        if (c)
          val[x] = -val[y];
        else
          val[x] = val[y];
      } else if (v[y] == 0) {
        v[y] = v[x];
        gr[v[x]].push_back(y);
        if (c)
          val[y] = -val[x];
        else
          val[y] = val[x];
      } else if (v[x] == v[y]) {
        if ((val[x] == val[y]) == c) {
          flag = true;
        }
      } else {
        bool smol = false;
        if ((val[x] == val[y]) == c) {
          smol = true;
        }
        long long szx = (long long)gr[v[x]].size(),
                  szy = (long long)gr[v[y]].size();
        if (szx < szy) {
          long long del = v[x];
          for (size_t i = 0; i < szx; i++) {
            gr[v[y]].push_back(gr[v[x]][i]);
            v[gr[v[x]][i]] = v[y];
            if (smol) {
              val[gr[v[x]][i]] = -val[gr[v[x]][i]];
            }
          }
          gr[del].clear();
        } else {
          long long del = v[y];
          for (size_t i = 0; i < szy; i++) {
            gr[v[x]].push_back(gr[v[y]][i]);
            v[gr[v[y]][i]] = v[x];
            if (smol) {
              val[gr[v[y]][i]] = -val[gr[v[y]][i]];
            }
          }
          gr[del].clear();
        }
      }
    }
    if (flag) {
      cout << -1 << "\n";
      continue;
    }
    long long res = 0;
    for (size_t i = 0; i < (long long)gr.size(); i++) {
      long long sum = 0;
      for (size_t j = 0; j < (long long)gr[i].size(); j++) {
        if (val[gr[i][j]] == 1) sum++;
      }
      res += max(sum, (long long)gr[i].size() - sum);
    }
    for (size_t i = 1; i <= n; i++) {
      if (!val[i]) res++;
    }
    cout << res << "\n";
  }
  return 0;
}
