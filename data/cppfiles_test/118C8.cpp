#include <bits/stdc++.h>
using namespace std;
const int MX = 250005, mod = 998244353, g = 3;
const long long inv2 = (mod + 1) / 2;
int n;
long long fac[MX], inv[MX];
map<int, int> mp;
vector<int> adj[MX], p[MX];
long long pot(long long b, int p) {
  if (p < 0) {
    p %= mod - 1;
    p += mod - 1;
  }
  long long res = 1;
  while (p) {
    if (p & 1) (res *= b) %= mod;
    (b *= b) %= mod;
    p >>= 1;
  }
  return res;
}
int npo2(int n) {
  int res = 1;
  while (res < n) res <<= 1;
  return res;
}
void ntt(vector<int> &X, int inv) {
  int n = X.size();
  for (int i = 1, j = 0; i < n - 1; i++) {
    for (int k = n >> 1; (j ^= k) < k; k >>= 1)
      ;
    if (i < j) swap(X[i], X[j]);
  }
  vector<long long> wp(n >> 1, 1);
  for (int k = 1; k < n; k <<= 1) {
    long long wk = pot(g, inv * (mod - 1) / (k << 1));
    for (int j = 1; j < k; j++) wp[j] = wp[j - 1] * wk % mod;
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < int(k); j++) {
        int u = X[i + j], v = X[i + j + k] * wp[j] % mod;
        X[i + j] = u + v < mod ? u + v : u + v - mod;
        X[i + j + k] = u - v < 0 ? u - v + mod : u - v;
      }
    }
  }
  if (inv == -1) {
    long long nrev = pot(n, mod - 2);
    for (int i = 0; i < int(n); i++) X[i] = X[i] * nrev % mod;
  }
}
vector<int> operator*(vector<int> A, vector<int> B) {
  int sz = A.size() + B.size() - 1;
  int size = npo2(sz);
  A.resize(size), B.resize(size);
  ntt(A, 1), ntt(B, 1);
  for (int i = 0; i < size; i++) A[i] = 1ll * A[i] * B[i] % mod;
  ntt(A, -1);
  A.resize(sz);
  return A;
}
long long comb(int n, int k) {
  return fac[n] * inv[k] % mod * inv[n - k] % mod;
}
void main_() {
  cin >> n;
  for (int i = 0; i < int(n - 1); i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) mp[(int)adj[i].size() - (1 < i)]++;
  mp.erase(0);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (auto it : mp) {
    p[it.first].resize(it.second + 1);
    for (int i = 0; i <= it.second; i++)
      p[it.first][i] = comb(it.second, i) * pot(it.first, i) % mod;
    pq.emplace(p[it.first].size(), it.first);
  }
  while (pq.size() > 1) {
    int a = pq.top().second;
    pq.pop();
    int b = pq.top().second;
    pq.pop();
    p[a] = p[a] * p[b];
    pq.emplace(p[a].size(), a);
  }
  int a = pq.top().second;
  pq.pop();
  long long res = 0;
  for (int i = 0; i < int(p[a].size()); i++)
    (res += (i % 2 == 0 ? 1 : -1) * fac[n - i] * p[a][i]) %= mod;
  cout << ((((res) % (mod)) + (mod)) % (mod)) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fac[0] = inv[0] = 1;
  for (int i = 1; i < MX; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = pot(fac[i], -1);
  }
  int t = 1;
  while (t--) main_();
  return 0;
}
