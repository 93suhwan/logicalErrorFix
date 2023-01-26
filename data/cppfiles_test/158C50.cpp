#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
const long long intmax = 2147483647;
const long long intmin = -2147483648;
const long long mod2 = 998244353;
const long long mod = 1e9 + 7;
const long long N = 3e5;
long long fact[N];
long long add(long long a, long long b, long long p = mod) {
  long long res = (a % p + b % p) % p;
  return res;
}
long long sub(long long a, long long b, long long p = mod) {
  long long res = (a % p - b % p + p) % p;
  return res;
}
long long mul(long long a, long long b, long long p = mod) {
  long long res = ((a % p) * (b % p)) % p;
  return res;
}
void factorial(long long n, long long p = mod) {
  fact[0] = 1;
  for (long long i = 1; i < n; i++) {
    fact[i] = mul(i, fact[i - 1], p);
  }
}
long long binExp(long long x, long long y, long long p = mod) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInv(long long i, long long p = mod) { return binExp(i, p - 2, p); }
long long ncr(long long n, long long r, long long p = mod) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fact[n] * modInv(fact[r], p) % p * modInv(fact[n - r], p) % p) % p;
}
long long divi(long long a, long long b, long long p = mod) {
  long long binv = modInv(b, p);
  long long res = ((a % p) * (binv % p)) % p;
  return res;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) in >> i;
  return in;
}
template <typename T>
ostream &operator<<(ostream &ost, vector<T> v) {
  if (&ost == &cerr) {
    cerr << "{";
    long long cnt = v.size();
    for (auto x : v) {
      cerr << x;
      cnt--;
      if (cnt) cerr << ", ";
    }
    cerr << "}";
  } else
    for (auto i : v) ost << i << " ";
  return ost;
}
template <typename T>
ostream &operator<<(ostream &ost, set<T> s) {
  if (&ost == &cerr) {
    cerr << "{";
    long long cnt = s.size();
    for (auto x : s) {
      cerr << x;
      cnt--;
      if (cnt) cerr << ", ";
    }
    cerr << "}";
  } else
    for (auto i : s) ost << i << " ";
  return ost;
}
template <typename U, typename V>
ostream &operator<<(ostream &ost, map<U, V> &m) {
  if (&ost == &cerr) {
    cerr << "{";
    long long cnt = m.size();
    for (auto x : m) {
      cerr << x;
      cnt--;
      if (cnt) cerr << ", ";
    }
    cerr << "}";
  } else
    for (auto i : m) ost << i;
  return ost;
}
template <typename U, typename V>
istream &operator>>(istream &in, pair<U, V> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename U, typename V>
ostream &operator<<(ostream &ost, pair<U, V> p) {
  if (&ost == &cerr)
    ost << "{" << p.first << ": " << p.second << "}";
  else
    ost << p.first << " " << p.second << " ";
  return ost;
}
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void print(T... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
void solution() {
  long long ans = -1;
  long long n, m;
  read(n, m);
  ;
  vector<long long> x(n);
  cin >> x;
  vector<vector<long long> > a(n, vector<long long>(m));
  for (long long i = 0; 0 <= n ? i < n : i >= n; 0 < n ? i += 1 : i -= 1)
    for (long long j = 0; 0 <= m ? j < m : j >= m; 0 < m ? j += 1 : j -= 1) {
      scanf("%1d", &a[i][j]);
    }
  vector<long long> best;
  for (long long mask = 0; 0 <= 1 << n ? mask < 1 << n : mask >= 1 << n;
       0 < 1 << n ? mask += 1 : mask -= 1) {
    vector<long long> val(m);
    for (long long i = 0; 0 <= n ? i < n : i >= n; 0 < n ? i += 1 : i -= 1) {
      for (long long j = 0; 0 <= m ? j < m : j >= m; 0 < m ? j += 1 : j -= 1) {
        if (a[i][j]) {
          val[j] += ((mask >> i) & 1) ? +1 : -1;
        }
      }
    }
    vector<long long> p(m);
    iota(p.begin(), p.end(), 0LL);
    long long res = 0;
    for (long long i = 0; 0 <= n ? i < n : i >= n; 0 < n ? i += 1 : i -= 1)
      res += ((mask >> i) & 1) ? -x[i] : x[i];
    sort(p.begin(), p.end(),
         [&](long long a, long long b) { return val[a] < val[b]; });
    for (long long i = 0; 0 <= m ? i < m : i >= m; 0 < m ? i += 1 : i -= 1) {
      res += val[p[i]] * (i + 1);
    }
    if (res > ans) ans = res, best = p;
  }
  vector<long long> ansPerm(m);
  for (long long i = 0; 0 <= m ? i < m : i >= m; 0 < m ? i += 1 : i -= 1)
    ansPerm[best[i]] = i + 1;
  cout << ansPerm << "\n";
}
signed main() {
  long long test = 1;
  cin >> test;
  for (long long t = 1; t <= test; t++) {
    solution();
  }
  return 0;
}
