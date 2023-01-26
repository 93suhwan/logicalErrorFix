#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MOD = 998244353;
const char nl = '\n';
const int MX = 200001;
struct mi {
  long long v;
  explicit operator long long() const { return v; }
  mi() { v = 0; }
  mi(long long _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
  mi& operator+=(const mi& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mi& operator*=(const mi& m) {
    v = v * m.v % MOD;
    return *this;
  }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi pow(mi a, long long p) {
    mi ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mi operator-() const { return mi(-v); }
  mi& operator++() { return *this += 1; }
  mi& operator--() { return *this -= 1; }
  mi operator++(int) {
    mi temp;
    temp.v = v++;
    return temp;
  }
  mi operator--(int) {
    mi temp;
    temp.v = v--;
    return temp;
  }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
  friend ostream& operator<<(ostream& os, const mi& m) {
    os << m.v;
    return os;
  }
  friend istream& operator>>(istream& is, mi& m) {
    long long x;
    is >> x;
    m.v = x;
    return is;
  }
};
void __print(mi X) { cout << X.v; }
mi facs[MX];
mi facInvs[MX];
mi choose(mi _a, mi _b) {
  long long a = (long long)_a, b = (long long)_b;
  if (b > a) return 0;
  if (a < 0) return 0;
  if (b < 0) return 0;
  mi cur = facs[a];
  cur = cur * facInvs[b];
  cur = cur * facInvs[a - b];
  return cur;
}
void initFacs() {
  facs[0] = 1;
  for (int i = 1; i < (MX); i++) {
    facs[i] = (facs[i - 1] * i);
  }
  facInvs[MX - 1] = inv(facs[MX - 1]);
  for (int i = (MX - 1) - 1; i >= 0; i--) {
    facInvs[i] = facInvs[i + 1] * (i + 1);
  }
}
long long modExp(long long base, long long power) {
  if (power == 0) {
    return 1;
  } else {
    long long cur = modExp(base, power / 2);
    cur = cur * cur;
    cur = cur % MOD;
    if (power % 2 == 1) cur = cur * base;
    cur = cur % MOD;
    return cur;
  }
}
long long inv(long long base) {
  int g = MOD, r = base, x = 0, y = 1;
  while (r != 0) {
    int q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return x < 0 ? x + MOD : x;
}
long long mul(long long A, long long B) { return (A * B) % MOD; }
long long add(long long A, long long B) { return (A + B) % MOD; }
long long dvd(long long A, long long B) { return mul(A, inv(B)); }
long long sub(long long A, long long B) { return (A - B + MOD) % MOD; }
namespace NTT {
vector<long long> roots = {0, 1};
vector<int> bit_reverse;
int max_size = -1;
long long root;
bool is_power_of_two(int n) { return (n & (n - 1)) == 0; }
int round_up_power_two(int n) {
  while (n & (n - 1)) n = (n | (n - 1)) + 1;
  return max(n, 1);
}
int get_length(int n) {
  assert(is_power_of_two(n));
  return __builtin_ctz(n);
}
void bit_reorder(int n, vector<long long>& values) {
  if ((int)bit_reverse.size() != n) {
    bit_reverse.assign(n, 0);
    int length = get_length(n);
    for (int i = 0; i < n; i++)
      bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
  }
  for (int i = 0; i < n; i++)
    if (i < bit_reverse[i]) swap(values[i], values[bit_reverse[i]]);
}
void find_root() {
  max_size = 1 << __builtin_ctz(MOD - 1);
  root = 2;
  while (!(modExp(root, max_size) == 1 && modExp(root, max_size / 2) != 1))
    root++;
}
void prepare_roots(int n) {
  if (max_size < 0) find_root();
  assert(n <= max_size);
  if ((int)roots.size() >= n) return;
  int length = get_length(roots.size());
  roots.resize(n);
  while (1 << length < n) {
    long long z = modExp(root, max_size >> (length + 1));
    for (int i = 1 << (length - 1); i < 1 << length; i++) {
      roots[2 * i] = roots[i];
      roots[2 * i + 1] = (roots[i] * z) % MOD;
    }
    length++;
  }
}
void fft_iterative(int N, vector<long long>& values) {
  assert(is_power_of_two(N));
  prepare_roots(N);
  bit_reorder(N, values);
  for (int n = 1; n < N; n *= 2)
    for (int start = 0; start < N; start += 2 * n)
      for (int i = 0; i < n; i++) {
        long long even = values[start + i];
        long long odd = values[start + n + i] * roots[n + i];
        odd %= MOD;
        values[start + n + i] = even - odd + MOD;
        values[start + i] = even + odd;
        values[start + n + i] %= MOD;
        values[start + i] %= MOD;
      }
}
const int FFT_CUTOFF = 150;
vector<long long> mod_multiply(vector<long long> left,
                               vector<long long> right) {
  int n = left.size();
  int m = right.size();
  if (min(n, m) < FFT_CUTOFF) {
    const uint64_t ULL_BOUND =
        numeric_limits<uint64_t>::max() - (uint64_t)MOD * MOD;
    vector<uint64_t> result(n + m - 1, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        result[i + j] += (uint64_t)((int)left[i]) * ((int)right[j]);
        if (result[i + j] > ULL_BOUND) result[i + j] %= MOD;
      }
    for (uint64_t& x : result)
      if (x >= MOD) x %= MOD;
    return vector<long long>(result.begin(), result.end());
  }
  int N = round_up_power_two(n + m - 1);
  left.resize(N);
  right.resize(N);
  bool equal = left == right;
  fft_iterative(N, left);
  if (equal)
    right = left;
  else
    fft_iterative(N, right);
  long long inv_N = inv(N);
  for (int i = 0; i < N; i++) {
    left[i] *= (right[i] * inv_N) % MOD;
    left[i] %= MOD;
  }
  reverse(left.begin() + 1, left.end());
  fft_iterative(N, left);
  left.resize(n + m - 1);
  return left;
}
vector<long long> mod_power(const vector<long long>& v, int exponent) {
  assert(exponent >= 0);
  vector<long long> result = {1};
  if (exponent == 0) return result;
  for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
    result = mod_multiply(result, result);
    if (exponent >> k & 1) result = mod_multiply(result, v);
  }
  return result;
}
vector<long long> mod_multiply_all(
    const vector<vector<long long>>& polynomials) {
  if (polynomials.empty()) return {1};
  struct compare_size {
    bool operator()(const vector<long long>& x, const vector<long long>& y) {
      return x.size() > y.size();
    }
  };
  priority_queue<vector<long long>, vector<vector<long long>>, compare_size> pq(
      polynomials.begin(), polynomials.end());
  while (pq.size() > 1) {
    vector<long long> a = pq.top();
    pq.pop();
    vector<long long> b = pq.top();
    pq.pop();
    pq.push(mod_multiply(a, b));
  }
  return pq.top();
}
}  // namespace NTT
using namespace NTT;
vector<int> comps;
long long half = 499122177;
vector<vector<long long>> get(int L, int R) {
  if (L == R) {
    vector<vector<long long>> res(4, vector<long long>(1, 0));
    if (comps[L] == 1) {
      res[3][0] += half;
    } else
      res[0][0]++;
    return res;
  }
  int M = (L + R) / 2;
  vector<vector<long long>> A = get(L, M);
  vector<vector<long long>> B = get(M + 1, R);
  vector<vector<long long>> res(4, vector<long long>(R - L + 1, 0));
  for (int ma = 0; ma < (4); ma++) {
    for (int mb = 0; mb < (4); mb++) {
      vector<long long> cur = mod_multiply(A[ma], B[mb]);
      int X = ma % 2;
      if (M == L) {
        X = 0;
      }
      int Y = mb / 2;
      if (M + 1 == R) {
        Y = 0;
      }
      int pos = X + 2 * Y;
      int mul = 0;
      if (ma / 2) mul++;
      if (mb % 2) mul++;
      for (int i = 0; i < ((int)(cur).size()); i++) {
        res[pos][i + 1] += cur[i] << mul;
        res[pos][i + 1] %= MOD;
      }
      X = ma % 2;
      Y = mb / 2;
      pos = X + 2 * Y;
      for (int i = 0; i < ((int)(cur).size()); i++) {
        res[pos][i] += cur[i];
        res[pos][i] %= MOD;
      }
    }
  }
  return res;
}
void solve() {
  initFacs();
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < (N); i++) cin >> A[i];
  int cur = -1, rem = 0;
  for (int i = 0; i < (N); i++) {
    if (rem == 0) {
      cur = A[i];
      comps.push_back(A[i]);
      rem = A[i] - 1;
    } else {
      rem--;
      if (A[i] != cur) {
        cout << 0 << nl;
        return;
      }
    }
  }
  vector<vector<long long>> res = get(0, (int)(comps).size() - 1);
  vector<mi> vals((int)(comps).size());
  for (int i = 0; i < (4); i++) {
    for (int j = 0; j < ((int)(comps).size()); j++) {
      vals[j] += res[i][j];
    }
  }
  mi ans = 0;
  for (int i = 0; i < ((int)(comps).size()); i++) {
    mi cur = pow(mi(2), (int)(comps).size() - i) *
             facs[(int)(comps).size() - i] * vals[i];
    if (i % 2) {
      ans -= cur;
    } else {
      ans += cur;
    }
  }
  cout << ans << nl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
