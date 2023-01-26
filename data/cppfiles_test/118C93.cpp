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
const long long MOD = 998244353;
long long M = 998244353;
constexpr long long mAdd(long long a, long long b, long long c) {
  return (a + b >= c ? a + b - c : a + b);
}
constexpr long long mSub(long long a, long long b, long long c) {
  return (a < b ? a - b + c : a - b);
}
constexpr long long modPow(long long a, long long b, long long c) {
  return ((b & 1)    ? (a * modPow(a, b ^ 1, c) % c)
          : (b == 0) ? 1
                     : (modPow(a * a % c, b >> 1, c)));
}
template <int P>
void ntt(vector<int>& vec, bool inv) {
  int n = vec.size();
  for (int i = 0; i < n; ++i) {
    int t = 0;
    for (int j = 0; (1 << j) < n; ++j) {
      if (i & (1 << j)) t |= n >> (j + 1);
    }
    if (i < t) swap(vec[i], vec[t]);
  }
  int root = modPow(3, (inv ? (n - 1) : 1) * (long long)(P - 1) / n, P);
  for (int h = 1; h < n; h <<= 1) {
    long long curr = 1, mult = modPow(root, n / (2 * h), P);
    for (int j = 0; j < h; ++j) {
      for (int i = j; i < n; i += 2 * h) {
        long long v = (curr * vec[i ^ h]) % P;
        vec[i ^ h] = mSub(vec[i], v, P);
        vec[i] = mAdd(vec[i], v, P);
      }
      curr = (curr * mult) % P;
    }
  }
}
template <int P>
vector<int> polyMult(vector<int> a, vector<int> b) {
  int n = 1, t = (int)a.size() + b.size() - 1;
  while (n < t) n <<= 1;
  a.resize(n, 0);
  b.resize(n, 0);
  ntt<P>(a, 0);
  ntt<P>(b, 0);
  vector<int> c(n);
  int n_inv = modPow(n, P - 2, P);
  for (int i = 0; i < n; ++i) c[i] = (long long)a[i] * b[i] % P * n_inv % P;
  ntt<P>(c, 1);
  c.resize(t);
  return c;
}
void solve() {
  int n;
  cin >> n;
  fcalc(n + 1, M);
  vector<vector<int>> adj(n);
  vector<int> deg(n, -1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  deg[0]++;
  vector<vector<int>> vv;
  for (long long i = 0; i < n; i++) {
    if (deg[i] > 0) vv.push_back({1, deg[i]});
  }
  while (vv.size() > 1) {
    vector<vector<int>> nw;
    for (long long i = 0; i + 1 < vv.size(); i += 2) {
      nw.push_back(polyMult<MOD>(vv[i], vv[i + 1]));
    }
    if (vv.size() % 2) {
      nw.push_back(vv.back());
    }
    swap(vv, nw);
  }
  long long ans = 0;
  for (int i = 0; i < vv[0].size(); i++) {
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
