#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("trapv")
const long long mod = 1e9 + 7;
const long long maxs = 1e5 + 5;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long add(long long x, long long y) {
  long long res = x + y;
  return (res >= mod ? res - mod : res);
}
long long sub(long long x, long long y) {
  long long res = x - y;
  return (res <= 0 ? res + mod : res);
}
long long binpow(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long mul(long long x, long long y) {
  long long res = x * y;
  return (res >= mod ? res % mod : res);
}
long long inv(long long x) { return binpow(x, mod - 2); }
template <class T>
long long size(T &a) {
  return a.size();
}
template <class T>
void read(vector<T> &a) {
  for (long long i = 0; i < size(a); i++) cin >> a[i];
}
long long ceil2(long long a, long long b) {
  if (a == 0) return 0;
  return (a + b - 1) / b;
}
inline long long maxim(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
inline long long minim(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 64 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
long long allbit(long long n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(long long i) { return i && (i & -i) == i; }
void extendgcd(long long a, long long b, long long *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
template <class T>
class SegmentTree {
 public:
  SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
  SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));
  T query(int l, int r);
  void update(int idx, T val);

 private:
  T *tree;
  void buildTree(std::vector<T> data);
  int segTreeSize;
  T valueForExtraNodes;
  T (*combine)(T obj1, T obj2);
  int calculateSize(int n);
  T queryHelper(int l, int r, int st, int ed, int node);
};
template <class T>
SegmentTree<T>::SegmentTree(std::vector<T> data, T value,
                            T (*combine)(T obj1, T obj2)) {
  this->combine = combine;
  valueForExtraNodes = value;
  segTreeSize = calculateSize(data.size());
  buildTree(data);
}
template <class T>
SegmentTree<T>::SegmentTree(T ar[], int n, T value,
                            T (*combine)(T obj1, T obj2)) {
  this->combine = combine;
  valueForExtraNodes = value;
  segTreeSize = calculateSize(n);
  std::vector<T> data;
  for (int i = 0; i < n; i++) data.push_back(ar[i]);
  buildTree(data);
}
template <class T>
int SegmentTree<T>::calculateSize(int n) {
  int pow2 = 1;
  while (pow2 < n) {
    pow2 = pow2 << 1;
  }
  return 2 * pow2 - 1;
}
template <class T>
T SegmentTree<T>::query(int l, int r) {
  int st = 0, ed = segTreeSize / 2;
  return queryHelper(l, r, st, ed, 0);
}
template <class T>
T SegmentTree<T>::queryHelper(int l, int r, int st, int ed, int node) {
  if ((r < st) || (l > ed) || (l > r)) return valueForExtraNodes;
  if (st >= l && ed <= r) return tree[node];
  T leftVal = queryHelper(l, r, st, (st + ed) / 2, (2 * node + 1));
  T rightVal = queryHelper(l, r, (st + ed) / 2 + 1, ed, (2 * node + 2));
  return combine(leftVal, rightVal);
}
template <class T>
void SegmentTree<T>::buildTree(std::vector<T> data) {
  int n = data.size();
  tree = new T[segTreeSize];
  int extraNodes = (segTreeSize / 2 + 1) - n;
  for (int i = segTreeSize - 1; i >= 0; i--) {
    if (extraNodes > 0) {
      tree[i] = valueForExtraNodes;
      extraNodes--;
    } else if (n > 0) {
      tree[i] = data[n - 1];
      n--;
    } else
      tree[i] = combine(tree[(2 * i + 1)], tree[(2 * i + 2)]);
  }
}
template <class T>
void SegmentTree<T>::update(int idx, T val) {
  int segTreeIdx = (segTreeSize / 2) + idx;
  tree[segTreeIdx] = val;
  while (((segTreeIdx - 1) / 2) >= 0) {
    segTreeIdx = ((segTreeIdx - 1) / 2);
    if ((2 * segTreeIdx + 2) < segTreeSize)
      tree[segTreeIdx] =
          combine(tree[(2 * segTreeIdx + 1)], tree[(2 * segTreeIdx + 2)]);
    if (segTreeIdx == 0) break;
  }
}
const int N = 1e6 + 5;
bool prime[N + 1];
void primes() {
  fill_n(prime, N + 1, true);
  for (int i = 2; i * i <= N; i++) {
    if (prime[i] == true) {
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }
}
int phi[N + 1];
void etf() {
  int n = N;
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 2; i <= n; i++) phi[i] = i;
  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
    }
  }
}
vector<vector<int>> f(N);
void factors() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      f[j].push_back(i);
    }
  }
}
long long prime_factors(long long n) {
  set<int> p;
  long long cn = 0;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      p.insert(i);
      p.insert(n / i);
      n /= i;
    }
  }
  if (n > 1) {
    p.insert(n);
  }
  cerr << "p"
       << " ";
  _print(p);
  cerr << "\n";
  ;
  return p.size();
}
long long countDivisors(long long n) {
  long long cnt = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
int modInverse(int a, int m) {
  int m0 = m;
  int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long fact[200010];
void compute_fact(long long modVal) {
  fact[0] = 1;
  for (int i = 1; i <= 200004; i++) {
    fact[i] = (fact[i - 1] * i) % modVal;
  }
}
long long ncr_mod(long long n, long long r, long long modVal) {
  if (r == 0 || n == r) return 1;
  if (n < r) return 0;
  return (((fact[n] * modInverse(fact[r], modVal)) % modVal) *
          modInverse(fact[n - r], modVal)) %
         modVal;
}
long long findPreviousPowerOf2(long long n) {
  return 1LL << (long long)log2l(n);
}
long long previousPowerOfTwo(long long n) {
  if ((n && !(n & (n - 1LL))) == 1) {
    return (n >> 1LL);
  }
  while (n & n - 1LL) {
    n = n & n - 1LL;
  }
  return n;
}
long long nextPowerOfTwo(long long n) {
  long long value = 1LL;
  while (value <= n) {
    value = value << 1LL;
  }
  return value;
}
long long calprod(vector<long long> r) {
  long long res = 1;
  for (auto p : r) {
    res *= p;
  }
  return res;
}
int psq(int n) {
  if (sqrt(n) - floor(sqrt(n)) == 0) {
    return 1;
  }
  if (n <= 3) {
    return n;
  }
  int res = n;
  for (int i = 1; i <= n; i++) {
    int temp = i * i;
    if (temp > n)
      break;
    else
      res = min(res, 1 + psq(n - temp));
  }
  return res;
}
int getcount(int n, int k) {
  long long res = (n >> (k + 1)) << k;
  if ((n >> k) & 1) res += n & ((1ll << k) - 1);
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vp[i] = {x, y};
  }
  auto comp = [&](pair<int, int> a, pair<int, int> b) {
    int d1 = abs(a.first - a.second);
    int d2 = abs(b.first - b.second);
    return d1 < d2;
  };
  sort(vp.begin(), vp.end(), comp);
  reverse((vp).begin(), (vp).end());
  vector<int> cnt(n + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = vp[i].first; j <= vp[i].second; j++) {
      cnt[j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    int ans = vp[i].first;
    for (int j = vp[i].first + 1; j <= vp[i].second; j++) {
      if (cnt[ans] > cnt[j]) ans = j;
    }
    cout << vp[i].first << " " << vp[i].second << " " << ans << "\n";
  }
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cout << setprecision(6) << fixed;
  primes();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
