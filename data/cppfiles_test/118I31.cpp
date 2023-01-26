#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
const int maxv = 2e6 + 10;
const int maxn = 250010;
const int inf32 = 1e9 + 5;
const long long inf64 = 1e18 + 10;
const int mod = 998244353;
vector<int> g[maxn];
int nc[maxn], f[maxn];
int N;
int add(long long first, long long second) {
  return ((first + second) % mod + mod) % mod;
}
int mul(long long first, long long second) { return first * second % mod; }
void DFS(int v, int p) {
  for (int nv : g[v]) {
    if (nv == p) continue;
    DFS(nv, v);
    ++nc[v];
  }
}
namespace NTT {
const long long mod = 998244353;
inline long long add(long long first, long long second) {
  return (((long long)first + (long long)second) % mod + mod) % mod;
}
inline long long mul(long long first, long long second) {
  return (long long)first * (long long)second % mod;
}
inline long long qpow(long long first, long long n) {
  long long ret = 1ll;
  while (n) {
    if (n % 2) ret = mul(ret, first);
    first = mul(first, first);
    n >>= 1;
  }
  return ret;
}
vector<vector<long long>> poly;
void change(vector<long long>& second, int len) {
  int i, j, k;
  for (i = 1, j = len / 2; i < len - 1; i++) {
    if (i < j) swap(second[i], second[j]);
    k = len / 2;
    while (j >= k) {
      j = j - k;
      k = k / 2;
    }
    if (j < k) j += k;
  }
}
void NTT(vector<long long>& P, int op) {
  int len = P.size(), i, j, k;
  change(P, len);
  for (i = 1; i < len; i <<= 1) {
    long long gn = qpow(3ll, (mod - 1) / (i << 1));
    if (op == -1) gn = qpow(gn, mod - 2);
    for (j = 0; j < len; j += (i << 1)) {
      long long g = 1;
      for (k = 0; k < i; ++k, g = g * gn % mod) {
        long long first = P[j + k], second = mul(g, P[j + k + i]);
        P[j + k] = add(first, second);
        P[j + k + i] = add(first, -second);
      }
    }
  }
  if (op == -1) {
    long long inv = qpow(len, mod - 2);
    for (i = 0; i < len; ++i) P[i] = mul(P[i], inv);
  }
}
vector<long long> multiply(vector<long long> aa, vector<long long> bb) {
  int n = aa.size(), m = bb.size(), len = 1, i;
  while (len < n + m) len <<= 1;
  vector<long long> a(len), b(len);
  for (i = 0; i < n; ++i) a[i] = aa[i];
  for (i = 0; i < m; ++i) b[i] = bb[i];
  NTT(a, 1);
  NTT(b, 1);
  vector<long long> c(len);
  for (i = 0; i < len; ++i) c[i] = mul(a[i], b[i]);
  NTT(c, -1);
  while (!c.empty() && c.back() == 0) c.pop_back();
  return c;
}
vector<long long> solve(int l, int r) {
  vector<long long> ret;
  priority_queue<pair<int, vector<long long>>,
                 vector<pair<int, vector<long long>>>,
                 greater<pair<int, vector<long long>>>>
      q;
  for (auto p : poly) q.push({2, p});
  while (!q.empty()) {
    auto p1 = q.top();
    q.pop();
    if (q.empty()) {
      ret = p1.second;
      break;
    }
    auto p2 = q.top();
    q.pop();
    auto p3 = multiply(p1.second, p2.second);
    q.push({(int)p3.size(), p3});
  }
  return ret;
}
}  // namespace NTT
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  f[0] = 1;
  for (int i = 1; i <= N; ++i) f[i] = mul(f[i - 1], i);
  for (int i = 2; i <= N; ++i) {
    int first, second;
    cin >> first >> second;
    g[first].push_back(second);
    g[second].push_back(first);
  }
  DFS(1, 1);
  for (int i = 1; i <= N; ++i) {
    NTT::poly.push_back({1, nc[i]});
  }
  vector<long long> P = NTT::solve(0, NTT::poly.size() - 1);
  long long ans = 0;
  for (int k = 0; k <= min(N - 1, (int)P.size() - 1); ++k) {
    long long sign = 1;
    if (k & 1) sign = -1;
    long long val = mul(sign, P[k]);
    printf("P[%d] = %lld\n", k, P[k]);
    val = mul(val, f[N - k]);
    ans = add(ans, val);
  }
  cout << ans << endl;
}
