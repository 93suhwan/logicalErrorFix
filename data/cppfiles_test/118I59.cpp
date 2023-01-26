#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long gcd(long long x, long long y) {
  long long r;
  while (y != 0 && (r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y == 0 ? x : y;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long add(long long a, long long b, long long M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
long long mod_inv(long long a, long long m) {
  long long g = m, r = a, x = 0, y = 1;
  while (r != 0) {
    long long q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return mod(x, m);
}
long long nCr(long long n, long long k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
vector<long long> FA, INV;
void fcalc(long long n, long long M) {
  FA.resize(n + 1);
  FA[0] = 1;
  for (long long i = 1; i <= n; i++) {
    FA[i] = (FA[i - 1] * i) % M;
  }
}
void icalc(long long n, long long M) {
  INV.resize(n + 1);
  INV[n] = mod_inv(FA[n], M);
  for (long long i = n - 1; i >= 0; i--) {
    INV[i] = (INV[i + 1] * (i + 1)) % M;
  }
}
long long nCrM(long long n, long long r, long long M) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long a = FA[n];
  a *= INV[r];
  a %= M;
  a *= INV[n - r];
  a %= M;
  return a;
}
long long rand_int(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
ifstream fin;
ofstream fout;
template <typename T>
ostream& operator<<(ostream& output, const vector<T>& data) {
  for (const T& x : data) output << x << " ";
  return output;
}
template <typename T>
istream& operator>>(istream& input, vector<T>& data) {
  for (auto& item : data) {
    input >> item;
  }
  return input;
}
long long M = 998244353;
void NTT(vector<long long>& a, long long n, bool invert, long long x) {
  for (long long i = 0; i < n; i++) {
    long long y = 0;
    for (long long j = 0; j < __builtin_ctzll(n); j++) {
      if ((1LL << j) & i) {
        y |= (1LL << (__builtin_ctzll(n) - j - 1));
      }
    }
    if (y > i) swap(a[i], a[y]);
  }
  if (invert) x = mod_inv(x, M);
  for (long long s = 1; s < __builtin_ctzll(n) + 1; s++) {
    long long y = powerM(x, (n / (1LL << s)), M);
    for (long long j = 0; j < (n / (1LL << s)); j++) {
      long long r = 1;
      for (long long i = 0; i < (1LL << (s - 1)); i++) {
        long long u = a[i + j * (1LL << s)];
        long long v = (r * a[i + j * (1LL << s) + (1LL << (s - 1))]) % M;
        a[i + j * (1LL << s)] = u + v;
        if (a[i + j * (1LL << s)] > M) a[i + j * (1LL << s)] -= M;
        a[i + j * (1LL << s) + (1LL << (s - 1))] = u - v;
        if (a[i + j * (1LL << s) + (1LL << (s - 1))] < 0)
          a[i + j * (1LL << s) + (1LL << (s - 1))] += M;
        r *= y;
        r %= M;
      }
    }
  }
  if (invert) {
    long long invn = mod_inv(n, M);
    for (long long i = 0; i < n; i++) {
      a[i] = (a[i] * invn) % M;
    }
  }
  return;
}
vector<long long> mult(vector<long long>& a, vector<long long>& b,
                       long long x) {
  long long n = 1;
  while (n < ((long long)a.size()) + ((long long)b.size())) {
    n <<= 1;
  }
  vector<long long> v(n);
  vector<long long> Na(a.begin(), a.end());
  Na.resize(n, 0);
  vector<long long> Nb(b.begin(), b.end());
  Nb.resize(n, 0);
  long long y = powerM(x, (M - 1) / n, M);
  NTT(Na, n, 0, y);
  NTT(Nb, n, 0, y);
  v.resize(n, 0);
  for (long long i = 0; i < n; i++) {
    v[i] = ((Na[i] * Nb[i]) % M);
  }
  NTT(v, n, 1, y);
  v.resize(((long long)a.size()) + ((long long)b.size()) - 1, 0ll);
  return v;
}
void solve() {
  long long n;
  cin >> n;
  fcalc(n + 1, M);
  vector<vector<long long>> adj(n);
  vector<long long> deg(n, -1);
  for (long long i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  deg[0]++;
  vector<vector<long long>> vv;
  for (long long i = 0; i < n; i++) {
    if (deg[i] > 0) vv.push_back({1, deg[i]});
  }
  while (vv.size() > 1) {
    vector<vector<long long>> nw;
    for (long long i = 0; i + 1 < vv.size(); i += 2) {
      nw.push_back(mult(vv[i], vv[i + 1], 3));
    }
    if (vv.size() % 2) {
      nw.push_back(vv.back());
    }
    vv = nw;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans += FA[n - i] * vv[0][i];
      ans %= M;
    } else {
      ans -= FA[n - i] * vv[0][i];
      ans = mod(ans, M);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
