#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 5e5 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int G = 3;
const int Gi = 332748118;
const double eps = 1e-6;
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool chkmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
long long qpow(long long n, long long m) {
  long long ret = 1;
  while (m) {
    if (m & 1) ret = ret * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return ret;
}
long long getinv(long long a) { return qpow(a, mod - 2); }
int n;
vector<int> e[N];
long long fac[N];
void init() {
  fac[0] = 1;
  for (int i = 1; i <= N - 1; ++i) {
    fac[i] = fac[i - 1] * i % mod;
  }
}
int r[N], lim;
void ntt(vector<long long> &A, int type) {
  for (int i = 0; i <= lim - 1; ++i) {
    if (i < r[i]) swap(A[i], A[r[i]]);
  }
  for (int mid = 1; mid <= lim - 1; mid <<= 1) {
    long long Wn = qpow(type == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int j = 0; j <= lim - 1; j += (mid << 1)) {
      long long w = 1;
      for (int k = 0; k <= mid - 1; ++k, w = (w * Wn) % mod) {
        int x = A[j + k];
        int y = w * A[j + mid + k] % mod;
        A[j + k] = (x + y) % mod;
        A[j + mid + k] = (x - y + mod) % mod;
      }
    }
  }
  if (type == -1) {
    long long tmp = getinv(lim);
    for (int i = 0; i <= lim - 1; ++i) {
      A[i] = A[i] * tmp % mod;
    }
  }
}
vector<long long> operator*(vector<long long> A, vector<long long> B) {
  int len = A.size() + B.size() - 1;
  lim = 1;
  while (lim <= len) lim <<= 1;
  for (int i = 0; i <= lim - 1; ++i) {
    r[i] = (r[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
  }
  A.resize(lim);
  B.resize(lim);
  ntt(A, 1);
  ntt(B, 1);
  for (int i = 0; i <= lim - 1; ++i) {
    A[i] = A[i] * B[i] % mod;
  }
  ntt(A, -1);
  A.resize(len);
  return A;
}
vector<long long> solve(int l, int r) {
  if (l == r) {
    vector<long long> tmp({1, (int)e[l].size() - (l != 1)});
    return tmp;
  }
  int mid = (l + r) / 2;
  return solve(l, mid) * solve(mid + 1, r);
}
void main0() {
  init();
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  vector<long long> v = solve(1, n);
  long long ans = 0;
  for (int i = 0; i <= n - 1; ++i) {
    ans += (i & 1 ? -1 : 1) * v[i] * fac[n - i] % mod;
    ans %= mod;
  }
  ans += mod;
  ans %= mod;
  cout << ans << endl;
}
